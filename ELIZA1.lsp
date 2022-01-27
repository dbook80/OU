;;; -*- Mode: Lisp; Syntax: Common-Lisp; -*-
;;; Code from Paradigms of Artificial Intelligence Programming
;;; Copyright (c) 1991 Peter Norvig

;;;; File eliza1.lisp: Basic version of the Eliza program

;;; The basics are in auxfns.lisp; look for "PATTERN MATCHING FACILITY"

;; New version of pat-match with segment variables

(defun variable-p (x)
  "Is x a variable (a symbol beginning with `?')?"
  (and (symbolp x) (equal (elt (symbol-name x) 0) #\?)))

(defun pat-match (pattern input &optional (bindings no-bindings))
  "Match pattern against input in the context of the bindings"
  (cond ((eq bindings fail) fail)
        ((variable-p pattern)
         (match-variable pattern input bindings))
        ((eql pattern input) bindings)
        ((segment-pattern-p pattern)                ; ***
         (segment-match pattern input bindings))    ; ***
        ((and (consp pattern) (consp input)) 
         (pat-match (rest pattern) (rest input)
                    (pat-match (first pattern) (first input) 
                               bindings)))
        (t fail)))

(defun segment-pattern-p (pattern)
  "Is this a segment matching pattern: ((?* var) . pat)"
  (and (consp pattern)
       (starts-with (first pattern) '?*)))

;;; ==============================

(defun segment-match (pattern input bindings &optional (start 0))
  "Match the segment pattern ((?* var) . pat) against input."
  (let ((var (second (first pattern)))
        (pat (rest pattern)))
    (if (null pat)
        (match-variable var input bindings)
        ;; We assume that pat starts with a constant
        ;; In other words, a pattern can't have 2 consecutive vars
        (let ((pos (position (first pat) input
                             :start start :test #'equal)))
          (if (null pos)
              fail
              (let ((b2 (pat-match
                          pat (subseq input pos)
                          (match-variable var (subseq input 0 pos)
                                          bindings))))
                ;; If this match failed, try another longer one
                (if (eq b2 fail)
                    (segment-match pattern input bindings (+ pos 1))
                    b2)))))))

;;; ==============================

(defun rule-pattern (rule) (first rule))
(defun rule-responses (rule) (rest rule))

;;; ==============================

(defparameter *elika-rules*
 '((((?* ?x) hello (?* ?y))
    (How are you.  Please state your concern.))
   (((?* ?x) We have to (?* ?y))
    (Ormazd will help  ?y)
   (((?* ?x) who (?* ?y))
    (The god of light, the source of my power that ?y) (Ahriman ?y brother (A princess o$
   (((?* ?x) Look at this dark world Ormazd clearly isn't here what good (?* ?y))
    (I can use the power of ?y to heal the fertile grounds))
   (((?* ?x) what (?* ?y))
    (The land will imprison Ahriman again)
   (((?* ?x) when will (?* ?y))
    (Can we just begin the healing now?))
   ((((?* ?x) yes (?* ?y))
    (Are you saying yes just to say it?))(Good let us go then.)
   (((?* ?x) I feel (?* ?y))
    (I do too we need to save the world regardless though.))))


;;; ==============================

(defun eliza ()
  "Respond to user input using pattern matching rules."
  (loop
    (print 'eliza>)
    (write (flatten (use-eliza-rules (read))) :pretty t)))

(defun use-eliza-rules (input)
  "Find some rule with which to transform the input."
  (some #'(lambda (rule)
            (let ((result (pat-match (rule-pattern rule) input)))
              (if (not (eq result fail))
                  (sublis (switch-viewpoint result)
                          (random-elt (rule-responses rule))))))
        *eliza-rules*))

(defun switch-viewpoint (words)
  "Change I to you and vice versa, and so on."
  (sublis '((I . you) (you . I) (me . you) (am . are))
          words))

;;; ==============================

(defun flatten (the-list)
  "Append together elements (or lists) in the list."
  (mappend #'mklist the-list))

(defun mklist (x)
  "Return x if it is a list, otherwise (x)."
  (if (listp x)
      x
      (list x)))

(defun mappend (fn the-list)	
  "Apply fn to each element of list and append the results."
  (apply #'append (mapcar fn the-list)))

(defun random-elt (choices)
  "Choose an element from a list at random."
  (elt choices (random (length choices))))

;;; ==============================

;;;> (eliza)
;;;ELIZA> (hello there)
;;;(HOW DO YOU DO. PLEASE STATE YOUR PROBLEM.) 
;;;ELIZA> (i want to test this program)
;;;(WHAT WOULD IT MEAN IF YOU GOT TO TEST THIS PROGRAM) 
;;;ELIZA> (i could see if it works)
;;;(DO YOU REALLY THINK ITS LIKELY THAT IT WORKS)
;;;ELIZA> (no not really)
;;;(ARE YOU SAYING "NO" JUST TO BE NEGATIVE?) 
;;;ELIZA> (no)
;;;(ARE YOU SAYING "NO" JUST TO BE NEGATIVE?) 
;;;ELIZA> (forget it-- i was wondering how general the program is)
;;;(WHY DO YOU TELL ME YOU WERE WONDERING HOW GENERAL THE PROGRAM IS NOW?)
;;;ELIZA> (i felt like it)
;;;(WHAT OTHER FEELINGS DO YOU HAVE?) 
;;;ELIZA> (i feel this is enough)
;;;(DO YOU OFTEN FEEL THIS IS ENOUGH ?) 
;;;ELIZA> [Abort]

;;; ==============================
