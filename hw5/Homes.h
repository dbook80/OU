/********************************************************
This is the parent and child classes for the animal homes

    Donovan Booker      Fall 2017
*********************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<iterator>
using namespace std;

// parent class
class Homes{ 

    public:
       virtual void input(istream& ins) = 0;
       virtual void output(ostream& outs) = 0;
       virtual void load(istream& fin) = 0;
       virtual void save(ostream& fout) = 0;
};

//child classes
class jaguar:public Homes{
public:
    jaguar()
    {
        grass = 0;
        cover = false;
        material = " ";
        river = 0.0;
        rock = "";
    }
    void input(istream& ins)
    {
        cout <<"How tall do you want the grass to be(in feet)?\n";
        ins >> grass; 
        cout <<"Would you like a thermal comforter?\n";
        string tmp;
        ins >> tmp;
        if(tmp == "yes" || tmp == "Yes")
        {
            cover = true;
            cout<<"What kind of material do want the comforter to be?\n";
            ins >> material; 
        }
        else
        {
            cover = false;
        }
        cout <<"How long do you want the river to be(in feet)?\n";
        ins >> river; 
        cout <<"Do you want a rock formation to lay under in case of rain?\n";
        ins >> rock;
    }
    void output(ostream& outs)
    {
        outs << "Your Jaguar's Home" << endl;
        outs << "The height of your grass is " << grass << " feet" << endl;
        string tmp;
        outs << "Your decision to have a thermal comforter is " << tmp << endl;
        if(tmp == "yes" || tmp == "Yes")
        {
            cover = true;
            outs << "The material of your comforter will be "<< material << endl;
        }
        else
        {
            cover = false;
        }
        outs << "The length of your river is " << river << " feet" << endl;
        outs << "Your decision to have rock formation is "<< rock << endl;
    }
    void load(istream& fin)
    {
      fin >> grass;
      string tmp;
      fin >> tmp;
      if(tmp == "yes" || tmp == "Yes")
      {
          cover = true;
          fin >> material; 
      }
      else
      {
          cover = false;
      }
      fin >> river;
      fin >> rock;
    }
    void save(ostream& fout)
    {
        fout << "Your Jaguar's Home" << endl;
        fout << "The height of your grass is " << grass << " feet" << endl;
        fout << "Your decision to have a thermal comforter is " << cover << endl;
        string tmp;
        if(tmp == "yes" || tmp == "Yes")
        {
            cover = true;
            fout << "The material of your comforter will be "<< material << endl;
        }
        else
        {
            cover = false;
        }
        fout << "The length of your river is " << river << " feet" << endl;
        fout << "Your decision to have rock formation is "<< rock << endl;
    }
private:
    int grass;
    bool cover;
    string material;
    double river;
    string rock;
};

class pig:public Homes{
public:
    pig()
    {
        mud = 0;
        windows = "";
        fence = false;
        length = 0.0;
        width = 0.0;
        height = 0.0;
        house = "";
    }
    void input(istream& ins)
    {
        cout<<"How deep do you want the mud to be(in centimeters)\n";
        ins >> mud;
        cout<<"Would you like a home made of straws, sticks, bricks or something else?\n"; //see what I did there? lol
        ins >> house;
        cout<<"Would you like to have windows in your home?\n";
        ins >> windows;
        cout<<"Would you like your home to have a fence?\n";
        string tmp;
        ins >> tmp;
        if(tmp == "Yes" || tmp == "yes")
        {
            fence = true;
            cout<<"What would you like the dimensions of your fence to be(in feet)?\n";
            ins >> length;
            ins >> width;
            ins >> height;
        }
        else
        {
            fence = false;
        }
    }
    void output(ostream& outs)
    {
        outs << "Your Pig Home" << endl;
        outs << "The depth of your mud pool is " << mud << " cm" << endl;
        outs << "Your house will be created out of " << house << endl;
        outs << "Your decision to have a fence is a " << fence << endl;
        string tmp;
        if(tmp == "Yes" || tmp == "yes")
        {
            outs << "The length of the fence will be " << length << " feet" << endl;
            outs << "The width of the fence will be " << width << " feet" << endl;
            outs << "The height of the fence will be " << height << " feet" << endl;
        }
        outs << "Your decision to have windows is a "<< windows << endl;
    }
    void load(istream& fin)
    {
      fin >> mud;
      fin >> windows;
      string tmp;
      fin >> tmp;
      if(tmp == "Yes" || tmp == "yes")
      {
          fence = true;
          cout<<"What would you like the dimensions of your fence to be(in feet)?\n";
          fin >> length;
          fin >> width;
          fin >> height;
      }
      else
      {
          fence = false;
      }
    }
    void save(ostream& fout)
    {
        fout << "Your Jaguar Home" << endl;
        fout << "The depth of your mud pool is " << mud << endl;
        fout << "Your house will be created out of " << house << endl;
        fout << "Your decision to have a fence is a " << fence << endl;
        string tmp;
        if(tmp == "Yes" || tmp == "yes")
        {
            fence = true;
            fout << "The length of the fence will be " << length << " feet" << endl;
            fout << "The width of the fence will be " << width << " feet" << endl;
            fout << "The height of the fence will be " << height << " feet" << endl;
        }
        else
        {
            fence = false;
        }
        fout << "Your decision to have windows is a "<< windows << endl;
    }
private:
    int mud;
    string windows;
    bool fence;
    double length, width, height;
    string house;
};

class bat:public Homes{ // Bats move a lot
public:
    bat()
    {
        location = "";
        roosts = 0;
    }
    void input(istream& ins)
    {
        cout<<"Would you prefer to be in a cave or a shed?\n";
        ins >> location;
        cout<<"How many roosts would you like?\n";
        ins >> roosts;
    }
    void output(ostream& outs)
    {
        outs << "Your Bat's Home" << endl;
        outs << "The location of your home is a " << location << endl;
        outs << "The amount of roosts you requested is " << roosts << endl;
    }
    void load(istream& fin)
    {
      fin >> location;
      fin >> roosts;
    }
    void save(ostream& fout)
    {
        fout << "Your Bat's Home" << endl;
        fout << "The location of your home is a " << location << endl;
        fout << "The amount of roosts you requested is " << roosts << endl;
    }
private:
    string location;
    int roosts;
};

class gorilla:public Homes{//Gorillas build tree or ground nests
public:
    gorilla()
    {
        nest = 't';
        plants = "";
        bushes = "";
        vines = "";
        sheet = false;
        cover = "";
        tree = "oak";
    }
    void input(istream& ins)
    {
        cout<<"Do you prefer the tree nest(enter t) or the ground nest(enter g)?\n";
        ins >> nest;
        if(nest == 't')
        {
            cout<<"What kind of tree do you want\n";
            ins >> tree;              
        }
        else if(nest == 'g')
        {
            cout<<"What kind of plants do you need?\n";
            ins >> plants;
            cout<<"What kind of bushes do you need?\n";
            ins >> bushes;
        }
        cout<<"Do you want trees to have vines\n";
        ins >> vines;
        cout<<"Would you like a thermal comforter or a fleece blanket?\n";
        string tmp;
        ins >> tmp;
        if(tmp == "Yes" || tmp == "yes")
        {
            sheet = true;
            cout<<"Which type of cover would you like?\n";
            ins >> cover;
        }
        else
        {
            sheet = false;
        }
    }
    void output(ostream& outs)
    {
        if(nest == 't')
        {
            outs << "Your Gorilla's Home" << endl;
            outs << "The type of tree you have requested is " << tree << endl;
            outs << "Your decision to have vines is " << vines << endl;
            string tmp;
            if(tmp == "Yes" || tmp == "yes")
            {
                sheet = true;
                outs << cover << endl;
            }
            else
            {
                sheet = false;
            }
        }
        else if(nest == 'g')
        {
            outs << "Your Gorilla's Home" << endl;
            outs << "The types of plants you have requested are " << plants << endl;
            outs << "The types of bushes you have requested are " << bushes << endl;
            outs << "Your decision to have vines is " << vines << endl;
            string tmp;
            if(tmp == "Yes" || tmp == "yes")
            {
                sheet = true;
                outs << cover << endl;
            }
            else
            {
                sheet = false;
            }
        }
    }
    void load(istream& fin)
    {
      fin >> nest;
      if(nest == 't')
      {
          fin >> tree;
      }
      if(nest == 'g')
      {
        fin >> plants;
        fin >> bushes;
      }
      fin >> vines;
      fin >> sheet;
      string tmp;
      fin >> tmp;
      if(tmp == "Yes" || tmp == "yes")
      {
          sheet = true;
          fin >> cover;
      }
      else
      {
          sheet = false;
      }
    }
    void save(ostream& fout)
    {
        if(nest == 't')
        {
            fout << "Your Gorilla's Home" << endl;
            fout << "The type of a tree you have requested is " << tree << endl;
            fout << "Your decision to have vines is " << vines << endl;
            string tmp;
            if(tmp == "Yes" || tmp == "yes")
            {
                sheet = true;
                fout << cover << endl;
            }
            else
            {
                sheet = false;
            }
        }
        else if(nest == 'g')
        {
            fout << "Your Gorilla's Home" << endl;
            fout << "The types of plants you have requested are " << plants << endl;
            fout << "The types of bushes you have requested are " << bushes << endl;
            fout << "Your decision to have vines is " << vines << endl;
            string tmp;
            
            if(tmp == "Yes" || tmp == "yes")
            {
                sheet = true;
                fout << cover << endl;
            }
            else
            {
                sheet = false;
            }
        }
    }
private:
    char nest;
    string plants;
    string bushes;
    string vines;
    bool sheet;
    string cover;
    string tree;
};

class lombax:public Homes{//lombax comes from the video game Ratchet and Clank, Ratchet is a lombax and a mechanic.
public:
    lombax()
    {
        garage = "";
        tool_drawer = "";
        boots = 0;
        length, width, height = 0.0;
    }
    void input(istream& ins)
    {
        cout<<"Do you want extra space in your garage for your ship?\n";
        ins >> garage;
        cout<<"Would you like to have a tool drawer for your mechanic work?\n";
        ins >> tool_drawer;
        cout<<"How many cupboard holes do you need?\n";//has different types of boots
        ins >> boots;
        cout<<"What dimensions of your closet do you need(in feet)?\n";//has accessories like a hoverboard and attachments for clank
        ins >> length;
        ins >> width;
        ins >> height;
    }
    void output(ostream& outs)
    {
        outs << "Your Lombax's Home" << endl;
        outs << "Your decision is have extra garage space is " << garage << endl;
        outs << "Your decision to have a tool drawer is " << tool_drawer << endl;
        outs << "The amount of cupboard holes you need is " << boots << endl;
        outs << "The length of your closet is " << length << " feet" << endl;
        outs << "The width of your closet is " << width << " feet" << endl;
        outs << "The height of your closet is " << height << " feet" << endl;
    }
    void load(istream& fin)
    {
      fin >> garage;
      fin >> tool_drawer;
      fin >> boots;
      fin >> length, width, height;
    }
    void save(ostream& fout)
    {
        fout << "Your Lombax's Home" << endl;
        fout << "Your decision is have extra garage space is " << garage << endl;
        fout << "Your decision to have a tool drawer is " << tool_drawer << endl;
        fout << "The amount of cupboard holes you need is " << boots << endl;
        fout << "The length of your closet is " << length << endl;
        fout << "The width of your closet is " << width << endl;
        fout << "The height of your closet is " << height << endl;
    }
private:
    string garage;
    string tool_drawer;
    int boots;
    double length, width, height;
};