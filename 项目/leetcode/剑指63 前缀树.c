/*在英语中，有一个叫做 词根(root) 的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子，需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

需要输出替换之后的句子。

*/
class Tire{
private:
    bool flag;
    vector<Tire*>children;
public:
    Tire():flag(false),children(26,nullptr){

    }
    void Tinsert(const string& word){
        Tire*tmp=this;//注意这里的调用者
        for(char w:word){
            if(tmp->children[w-'a']==nullptr){
                tmp->children[w-'a']=new Tire();
            }
            tmp=tmp->children[w-'a'];
        }
        tmp->flag=true;
    }
    int Tcount(const string&word){
        Tire*tmp=this;
        int len=0;
        for(char w:word){
            if(tmp->children[w-'a']==nullptr){
                return 0;
            }
            len++;
            tmp=tmp->children[w-'a'];
            if(tmp->flag==true){
                return len;
            }
        }
        return 0;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Tire*root=new Tire();
        //插入单词
        for(const string s:dictionary){
            root->Tinsert(s);
        }
        //分割长段
        vector<string>v{""};
        for(char a:sentence){
            if(a!=' '){
                v.back().push_back(a);
            }else{
                v.push_back("");
            }
        }
        //找到替换的子单词
        vector<string>tmp;
        for(string k:v){
            int len=root->Tcount(k);
            if(len==0){
                tmp.push_back(k);
            }else{
                tmp.push_back(k.substr(0,len));
            }
        }
        //拼接
        string fault="";
        for(string l:tmp){
            fault+=l;
            fault+=" ";
        }
        fault.pop_back();

        return fault;
    }
};
