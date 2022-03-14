// #Simplify Path
// # Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

// # In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

// # The canonical path should have the following format:

// #     The path starts with a single slash '/'.
// #     Any two directories are separated by a single slash '/'.
// #     The path does not end with a trailing '/'.
// #     The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')

// # Return the simplified canonical path.

 

// # Example 1:

// # Input: path = "/home/"
// # Output: "/home"
// # Explanation: Note that there is no trailing slash after the last directory name.

// # Example 2:

// # Input: path = "/../"
// # Output: "/"
// # Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

// # Example 3:

// # Input: path = "/home//foo/"
// # Output: "/home/foo"
// # Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stck;
        string res;
        string p = path;
        string p1;
        int pos = 0;
        
        while(!p.empty())
        {
            //Parse the string
            if (p.substr(0,1)=="/")         //handle first "/"
            {
                pos = 0;
                p1="/";
                p = p.substr(pos+1);
            }
            else
            {
                pos = p.find("/");
                if (pos!=string::npos)
                {
                    p1 = p.substr(0, pos);  //string upto "/"
                    p = p.substr(pos);      //remaining string
                }
                else
                {
                    p1 = p;
                    p="";
                }
                
            }
             
            //Add blocks to stack
            if(p1=="/")
            {
                if(stck.empty() || stck.back()!="/")
                    stck.push_back(p1);
            }
            else if (p1==".")
            {
                //do nothing
            }
            else if (p1=="..")
            {
                if(!stck.empty() && stck.back()=="/")
                    stck.pop_back();
                
                if (stck.empty())
                    stck.push_back("/");
                else
                    stck.pop_back();             //pop the top directory
            }
            else
            {
                stck.push_back(p1);              //p1 is name of directory
            }
            
        }
        
        if (stck.size()>1)
            if (stck.back()=="/")
                stck.pop_back();
        
        //Push contents of stack into result
        for (int i=0; i<stck.size(); i++)
        {
            res += stck[i];
        }
        
        return res;
    }
};