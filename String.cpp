#include<iostream>
using namespace std;

int Strlen(const char *);
char * Strcpy(char *,const char *);
char * Strcat(char *,const char *);
int Strcmp(char *,char*);

class String
{
    char *str;

    public:
    String()                                                //default constructor
    {
        //cout<<"default constructor"<<endl;
        str=nullptr;
    }
    
    String(const char * pstr)                               //parameterized constructor 
    {
        //cout<<"parameterized constructor"<<endl;
        int len=Strlen(pstr);
        str=new char[len+1];
        Strcpy(str,pstr);
    }

    String(String & cpstr)                                   //copy constructor
    {
        //cout<<"copy constructor"<<endl;
        if(cpstr.str==nullptr)
            str=nullptr;
        else
        {
            int len=Strlen(cpstr.str);
            str=new char[len+1];
            Strcpy(str,cpstr.str);
        }
    }

    ~String()                                               //destructor
    {
        //cout<<"destructor"<<endl;
        if(str!=nullptr)
            delete []str;
    }

    String & operator =(const String & astr)                //assignment operator string obj=obj1
    {
        //cout<<"assignmet both objects"<<endl;
        if(astr.str==nullptr)
            return *this;
        else
        {
            if(str!=nullptr)
                delete []str;
            int len=Strlen(astr.str);
            str=new char[len+1];
            Strcpy(str,astr.str);
        }
        return *this;
    }

    String & operator =(const char *astr)                   //assignment operator string obj="string"
    {
        //cout<<"assignmen op +string"<<endl;
        if(str!=nullptr)
            delete []str;
        int len=Strlen(astr);
        str=new char[len+1];
        Strcpy(str,astr);
        return *this;
    }
    
    String operator +(String & catstr)                      //+ operator obj=obj1+obj2
    {
        //cout<<"+ operator"<<endl;
        if(str==nullptr)
            return catstr;
        else if(catstr.str==nullptr)
            return *this;
        String temp;
        int len1,len2;
        len1=Strlen(str);
        len2=Strlen(catstr.str);
        temp.str=new char[len1+len2+1];
        Strcpy(temp.str,str);
        Strcat(temp.str,catstr.str);
        return temp;
    }
    
    String operator +(const char * opstr)                   //+ operator obj=obj1+"string"
    {
       // cout<<"+ operator"<<endl;
        String temp;
        if(str==nullptr)
        {
            temp=opstr;
            return temp;
        }
        else
        {
            int len1,len2;
            len1=Strlen(str);
            len2=Strlen(opstr);
            temp.str=new char[len1+len2];
            Strcpy(temp.str,str);
            Strcat(temp.str,opstr);
            return temp;
        }
    }

    char operator [](int i)
    {
        return str[i];
    }

    bool operator >(String ob)
    {
        if(Strcmp(str,ob.str)>0)
            return true;
        else
            return false;
    }

    bool operator >=(String ob)
    {
        if(Strcmp(str,ob.str)>=0)
            return true;
        else
            return false;
    }

    bool operator <(String ob)
    {
        if(Strcmp(str,ob.str)<0)
            return true;
        else
            return false;
    }

    bool operator <=(String ob)
    {
        if(Strcmp(str,ob.str)<=0)
            return true;
        else
            return false;
    }

    bool operator ==(String ob)
    {
        if(Strcmp(str,ob.str)==0)
            return true;
        else
            return false;
    }

    bool operator !=(String ob)
    {
        if(Strcmp(str,ob.str)!=0)
            return true;
        else
            return false;
    }
    //insertion and extraction functions declerations 
    friend istream & operator >>(istream & ,String &);
    friend ostream & operator <<(ostream & ,String &);

    //friend string functions
    friend String Strcpy(String &s2,String &s1);                    //written   //working
    friend String Strncpy(String &s2,String &s1,int n);             //written   //working
    friend int Strcmp(String &s2,String & s1);                      //written   //working
    friend int Strncmp(String & s2,String & s1,int n);              //written   //working
    friend String& Strcat(String & s2,String & s1);                 //written   //working
    friend String& Strncat(String &s2,String & s1,int n);           //written   //working
    friend String& Strrev(String & s);                              //writtem   //working
    friend String& Strupr(String & s);                              //written   //working
    friend String& Strlwr(String & s);                              //written   //working
    friend char* Strchr(String & s,char ch);                        //written   //working
    friend char* Strrchr(String & s1,char ch);                      //written   //working
    friend char* Strstr(String & s,const char * sub);               //written   //working
    friend int Strlen(String & s);                                  //written   //working
};

//extraction operator 
istream & operator >>(istream & in,String & s1)
{
    //cout<<"extraction op over loading"<<endl; 
    s1.str=new char[100];
    in>>s1.str;
    return in;
}

//insertion operator 
ostream & operator <<(ostream & out,String & s1)
{
    //cout<<"insertion operator over loading"<<endl;
    out<<s1.str;
    return out;
}

//string copy function for objects
String Strcpy(String &s2,String &s1)
{
    int len1,i;
    len1=Strlen(s1);
    if(s2.str!=nullptr)
        delete []s2.str;
    s2.str=new char[len1+1];
    for(i=0;s1.str[i];i++)
        s2.str[i]=s1.str[i];
    s2.str[i]='\0';

    return s2;
}

//string n copy function for objects
String Strncpy(String &s2,String &s1,int n)
{
    int len1,i;
    len1=Strlen(s1);
    if(s2.str!=nullptr)
        delete []s2.str;
    s2.str=new char[len1+1];
    for(i=0;i<n && s1.str[i];i++)
        s2.str[i]=s1.str[i];
    if(s1.str[i]=='\0' && i<n)
        s2.str[i]='\0';
    
    return s2;
}

//string compare with objects
int Strcmp(String &s2,String & s1)
{
    int i;
    for(i=0;s2.str[i];i++)
    {
        if(s2.str[i]!=s1.str[i])
            break;
    }
    if(s2.str[i]==s1.str[i])
        return 0;
    else
        if(s2.str[i]-s1.str[i]>0)
            return 1;
        else 
            return -1;  
}

//string n compare with objects  
int Strncmp(String & s2,String & s1,int n)                      //abcd
{                                                               //abde
    int i;
    for(i=0; i<n;i++)
    {
        if(s2.str[i]!=s1.str[i])
            break;
    }
    if(i==n)
        return 0;
    else
        if(s2.str[i]-s1.str[i]>0)
            return 1;
        else 
            return -1;
}

//string concat with objects
String& Strcat(String & s2,String & s1)
{
    int len1,len2,i,j;
    len1=Strlen(s1);
    len2=Strlen(s2);
    String temp;
    temp.str=new char[len1+len2+1];
    Strcpy(temp,s2);
    for(i=len2,j=0;s1.str[j];i++,j++)
        temp.str[i]=s1.str[j];
    temp.str[i]='\0';
    s2=temp;
    return s2;
}

//string n concat with objects
String& Strncat(String &s2,String & s1,int n)
{
    int len2,i,j;
    len2=Strlen(s2);
    String temp;
    temp.str=new char[len2+n+1];
    Strcpy(temp,s2);
    for(i=len2,j=0;j<n && s1.str[j];i++,j++)
        s2.str[i]=s1.str[j];
    if(s1.str[j]=='\0')
        s2.str[i]='\0';
    s2=temp;
    return s2;
}

//string reverse with object
String& Strrev(String & s)
{
    int i,j,len=Strlen(s);
    char ch;
    for(i=0,j=len-1;i<j;i++,j--)
    {
        ch=s.str[i];
        s.str[i]=s.str[j];
        s.str[j]=ch;
    }
    return s;
}

//string upper case with object
String& Strupr(String & s)
{
    int i;
    for(i=0;s.str[i];i++)
    {

        if(s.str[i]>='a' && s.str[i]<='z')
            s.str[i]=s.str[i]-32;
    }
    return s;
}

//string lower with object
String& Strlwr(String & s)
{
    int i;
    for(i=0;s.str[i];i++)
    {

        if(s.str[i]>='A' && s.str[i]<='Z')
            s.str[i]=s.str[i]+32;
    }
    return s;
}

//strchr with object
char * Strchr(String & s,char ch)
{
    int i;
    for(i=0;s.str[i];i++)
    {
        if(s.str[i]==ch)
            return s.str+i;
    }
    return 0;
}

//strrchr in strings with object
char* Strrchr(String & s,char ch)
{
    int i,len=Strlen(s);
    for(i=len-1;i>=0;i--)
    {
        if(s.str[i]==ch)
            return s.str+i;
    }
    return 0;
}

//string,sub string in objects 
char* Strstr(String & s,const char * sub)
{
    int i,j,k;
    for(i=0;s.str[i];i++)
    {
        for(j=i,k=0;sub[k];j++,k++)
        {
            if(s.str[j]!=sub[k])
                break;
        }
        if(sub[k]=='\0')
            return s.str+i;
    }
    return 0;
}

//string length friend function for object
int Strlen(String & s)
{
    int len;
    for(len=0;s.str[len];len++);
    return len;
} 

//String length function 
int Strlen(const char * s)
{
    if(s==nullptr)
        return 0;
    int i;
    for(i=0;s[i];i++);
    return i;
}

//String copy function 
char * Strcpy(char *d,const char *s)
{
    int len1,len2,i;
    len1=Strlen(d);
    len2=Strlen(s);
    for(i=0;i<=len2;i++)
    {
        d[i]=s[i];
    }
    return d;
}

//string concatination function
char * Strcat(char *d,const char *s)
{
    int len1,len2,i,j;
    len1=Strlen(d);
    len2=Strlen(s);
    for(i=len1,j=0;j<=len2;i++,j++)
    {
        d[i]=s[j];
    }
    return d;
}

//string coomparition function 
int Strcmp(char *s2 ,char*s1)
{
    int i;
    for(i=0;s2[i];i++)
    {
        if(s2[i]!=s1[i])
            break;
    }
    if(s2[i]==s1[i])
        return 0;
    else
        if(s2[i]-s1[i]>0)
            return 1;
        else 
            return -1; 
}

//main 
int main()
{
    String s1("hello");  //parameterized constructor
    cout<<"s1="<<s1<<endl;
    String s2=s1;       //copy constructor
    cout<<"s2="<<s2<<endl;
    String s3;
    s3=s2;              //assignment operator ob=obj
    cout<<"s3="<<s3<<endl;
    s3="world";         //assignment operator ob="string"
    cout<<"s3="<<s3<<endl;
    String s4;
    s4=s1+s3;           // '+' operator obj=obj1+obj2 
    cout<<"s4="<<s4<<endl;

    s4=s1+"good morning";//'+' operator obj=obj1+"string"
    cout<<"s4="<<s4<<endl;

    cout<<s4[0]<<endl;  // '[]' operator 
    
    if(s1==s2)                        //conditional operator
        cout<<"condition true"<<endl;
    else
        cout<<"condition false"<<endl;

    String s5;
    s5="lap top";
    cout<<"s5 len="<<Strlen(s5)<<endl;
    cout<<Strupr(s5)<<endl;
    // cout<<s5<<endl;
    cout<<Strlwr(s5)<<endl;
    // cout<<s5<<endl;
    cout<<Strrev(s5)<<endl;
    // cout<<s5<<endl;

    
}