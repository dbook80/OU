/*****************************************************
   This is the implementation file for fbfriends.
   This class is a container that holds Friends of the 
   class Friend. It uses an internal iterator to give the
   application the ability to order the container as well
   as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.
     Donovan Booker 	Fall 2017	Ohio University
*********************************************************/
#include<iostream>
#include"fbfriends.h"
#include<assert.h>

FBFriends::FBFriends()
{
  data = new Friend[5];
  used = 0;
  capacity = 5;
  current_index = 0;
}
	//The functions known as the Big 3
FBFriends::~FBFriends()
{
  delete []data;
}
FBFriends::FBFriends(const FBFriends& other)
{
  std::copy(other.data, other.data + used, data);
}
void FBFriends::operator = (const FBFriends& other)
{
  if(& other == this)
  {
    delete [] data;
    capacity = other.capacity;
    used = other.used;
    data = new Friend[capacity];
    std::copy(other.data, other.data + used, data);
  }
}
// Functions for the internal iterator
void FBFriends::start()
{
   current_index = 0;
}
void FBFriends::advance()
{
   if(is_item()==true)
   {
     current_index++;
   }
}
bool FBFriends::is_item()
{
  if(current_index <= used)
  {
    return true;
  }
  else
  {
    return false;
  }
}
Friend FBFriends::current()
{
  return data[current_index];
}
void FBFriends::remove_current()
{
  used--;
  assert(is_item() == true);

  for (int i = current_index; i < used; ++i)
  {
    data[i] = data[i+1];
  }
}
void FBFriends::insert(const Friend& f)
{
  if(used == capacity)
  {
    resize();
  }  
  if (is_item() == false)
  {
       current_index = 0;
  }   
  for (int i = used; i > current_index; --i)
  {
       data[i] = data[i-1];
  }   
  data[current_index] = f;
  ++used;
}
void FBFriends::attach(const Friend& f)
{
  if(used == capacity)
  {
    resize();
  }  
  for (int i = used; i > current_index; i--)
  {
    data[i] = data[i-1];
  }
  data[current_index + 1] = f;
  ++used;
}
void FBFriends::show_all(std::ostream& outs)const
{
  for(int i = 0; i < used; i++)
  {
     outs << data[i] << std::endl;
  }
}
void FBFriends::bday_sort()
{
  Friend tmp, tmp2;
  int i, j;
  for(i = 0; i < used; ++i)
  {
    for(j = 0; j < used - i - 1; ++j)
    {
      tmp = data[j];
      tmp2 = data[j+1];
      if(tmp.get_bday() > tmp2.get_bday())
      {
        data[j+1] = tmp;
        data[j] = tmp2;
      }
    }
  }
}
Friend FBFriends::find_friend(const std::string& name)const
{
  for(int i = 0; i < used; ++i)
  {
    if(name == data[i].get_name())
    {
      return data[i];
    }
  }
  Friend tmp;
  return tmp;
}
bool FBFriends::is_friend(const Friend& f) const
{
   Friend tmp;
   for(int i = 0; i < used; ++i)
   {
     tmp = data[i];
     if(f == tmp)
     {
       return true;
       break;
     }
   }
   return false;
}
void FBFriends::load(std::istream& ins)
{
  ins >> data[used];
  while(!ins.eof())
  {
    used++;
    if(used == capacity)
    {
      resize();
    }
    ins >> data[used];
  }
}
void FBFriends::save(std::ostream& outs)
{
  for(int i = 0; i < used; i++)
	{
		outs<< data[used] << std::endl;
	}
}
void FBFriends::resize()  // increases the capacity of the container by 5
{
   Friend * tmp;
   tmp = new Friend [capacity + 5];
   //copy(data, data + used, tmp); 
   for(int i = 0; i < used; ++i) 
   {
     tmp[i] = data[i];
   }
   capacity += 5;
   delete [] data;
   data = tmp; 
} 
 