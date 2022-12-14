#include <iostream>
#include <string.h>
#include <string>
#include "StringSet.h"
using namespace std;

//Start Writing
class StringSet
{
  /*
     should have the following private member variables

     A pointer to a string that will be used to point to an array of strings in dynamic memory
     An int that records the current size of the array (the number of values stored in the array)
     An int that records the maximum size of the array

   */
private:
  string * arr;
  int current_size;
  int max_size;


public:

/*
    default constructor b  creates an array of strings of size 2 in dynamic memory and assigns its address to the class' double array pointer, sets maximum size to 2, and current size to 0
    */

    StringSet ()
  {
    arr = new string[2];
    max_size = 2;
    current_size = 0;


  }
/*
copy constructor b  creates a deep copy of its constant StringClass reference parameter

Step 1 Create a new object - then copy it somehow

*/
  StringSet (StringSet & st)
  {
    max_size = st.max_size;
    current_size = st.current_size;
    arr = new string[max_size];

    arr = st.arr;		///????????

    for (int ii = 0; ii < st.current_size; ii++)
      {


	st.arr[ii] = arr[ii];
//	strcpy(st.arr[ii],arr[ii]);                   
      }


/*
Can I use a for loop to copy?

for(int ii=0;ii<s.max_size();ii++){

                               
  }
strcpy (str2,str1);
char * strcpy ( char * destination, const char * source );

*/


  }


  /*
     destructor b  deallocates dynamic memory associated with the objectb s string (array) pointer
   */
  ~StringSet ()
  {
    delete[]arr;
  };



/*
overloaded assignment operator b  deep copies its constant StringClass reference parameter to the calling object; deallocates dynamic memory associated with the calling object's original array; returns a reference to the calling object; should behave correctly during self-assignment
*/

  StringSet& operator=(const StringSet& st)
  {
    //Copy first
//Deallocate? Use delete[] arr; ?

//Can I copy from the constructor

//Deep Copy here

delete[] arr;

max_size = st.max_size;
    current_size = st.current_size;
    arr = new string[max_size];

    arr = st.arr;		///????????

    for (int ii = 0; ii < st.current_size; ii++)
      {


	st.arr[ii] = arr[ii];
//	strcpy(st.arr[ii],arr[ii]);                   
      }
  
return *this;
  }				//?????????

/*
insert ???returns false (a bool, not an int) without inserting value if a string matching the parameter is already in the array, otherwise: inserts its string parameter at the next available index; if the underlying array is full, doubles the maximum size attribute, creates an array of twice the size of the current array, copies the contents of the old array to the new array, frees memory associated with the old array, and assigns new array???s address to object???s array pointer, then inserts parameter; increments current size and returns true
*/

  bool insert (string str)
  {
    /// finish later
    /*
    if (find(str) >= 0){
      //  cout << arr << endl;
      return false;
    }

    if(current_size-1 == max_size){
     //Checking if the last element is max size location
     arr = (string*) realloc(arr, 2*sizeof(arr));

    }

    //If it reaches here, it means that find didn't find anything and current_size = or greater than max_size

  // cout << &str << endl;
      arr[current_size] = str; //
      current_size++;
      
     cout << arr[current_size-1] << endl;
    return true;
    
    Code not working. Gets a segmentation fault after a couple entrues. But keeping this and making a new one
    */

        for(int i=0;i<current_size;i++){
                                if(arr[i].compare(str)==0){
                                        return false;
                                }
                        }
                        if(current_size==max_size){
                                max_size = 2*max_size;
                                string* temp = new string[max_size];
                                for(int i=0;i<current_size;i++){
                                        temp[i] = arr[i];
                                }
                                delete[] arr;
                                arr = temp;
                        }
                        arr[current_size] = str;
                        current_size++;
                        return true;
  }

/*
remove ??? if a string matching its string parameter is in the array replaces the matching string with the last string in the array (if there is one) and decrements current size
*/
  void remove (string str)
  {
    //finish later
    if (find(str) == -1)
  {
    cout << "String not found" << endl;
  }

  else{
    arr[find(str)] = arr[current_size-1];
    current_size--;
  }

  }
/*
find ??? if a string matching the string parameter is in the array returns the integer index of that string, otherwise returns -1
*/
  int find (string st)
  {
    for (int ii = 0; ii < current_size; ii++)
      {
        cout<<"in find" << arr[ii]<<endl;
	if (arr[ii].compare(st) == 0)
	  {
	    return ii;
	  }
      }

      return -1;
}

/*
Size ??? returns an integer equal to the number of values in the calling object
*/

int size(){
  return current_size;
}

/*

unions ??? returns a StringSet object that contains the union of the calling object and the StringSet parameter (if the result is the empty set the returned StringSet object???s current size should equal zero); neither the calling object nor the parameter should be modified; in case you were wondering, this method is called unions because union is a reserved word
*/
    StringSet unions(StringSet& stra){
                        StringSet result(stra);
                        for(int i=0;i<current_size;i++){
                                result.insert(arr[i]);
                        }
                        return result;
                }

/*
intersection ??? returns a StringSet object that contains the intersection of the calling object and its StringSet parameter (if the result is the empty set the returned StringSet object???s current size should equal zero); neither the calling object nor the parameter should be modified
*/
 StringSet intersection(StringSet& stra){
                        StringSet result;
                        for(int i=0;i<current_size;i++){
                                if(stra.find(arr[i])!=-1){
                                        result.insert(arr[i]);
                                }
                        }
                        return result;
                }

/*
difference ??? returns a StringSet object that contains the set difference of the calling object and its StringSet parameter, i.e. calling object - parameter (if the result is the empty set the returned StringSet object???s current size should equal zero); neither the calling object nor the parameter should be modified

*/

  StringSet difference(StringSet& stra){
                        StringSet result(*this);
                        for(int i=0;i<stra.size();i++){
                                result.remove(arr[i]);
                        }
                        return result;
                }
// print function to help with testing
/*
 void printer(){
       for(int i=0;i<this->current_size;i++){
                               cout << arr[i] << endl;
                        }
  }
*/
  };
  
  
 

  int main ()
  {

   
    StringSet test_string;
    test_string.insert("apple");
    cout<<"completed insert";
    std::cout << test_string.find("apple")<<endl;
    std::cout << test_string.find("banana")<<endl;
test_string.insert("cabbage");
test_string.insert("dog");

StringSet union_string;

union_string.insert("apple");
union_string.insert("banana");
union_string.insert("dog");       

StringSet full_union = test_string.unions(union_string);
// 


cout << "starting testU()...\n\n";
    StringSet ss1;
    ss1.remove("aaa"); //remove on nothing case
    ss1.insert("aaa");
    ss1.insert("bbb");
    ss1.insert("ccc");
    ss1.insert("ddd");

    StringSet ss2;
    ss2.insert("ccc");
    ss2.insert("ddd");
    ss2.insert("ccc"); //double insert case
    ss2.insert("zzz");
    ss2.insert("yyy");

 //   StringSet ss3 = ss1.difference(ss2);
  //  cout << "ss3 should be: aaa bbb ccc ddd zzz yyy\n";
    cout << "ss3 is       : " << endl;
    //ss3.printer();
    
    
   // delete *ss2;
 //   ss2.printer();

    cout << "\ntestU() complete.\n-------------\n";

return 0;
  }
  
 