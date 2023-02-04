 string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        
        string res = "";
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                res.append("#,");
            }

            else
            {
                res += to_string(curr->val)+',';
                if (curr->left)
                {
                    q.push(curr->left);
                }
                else
                {
                    q.push(NULL);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
                else
                {
                    q.push(NULL);
                }
            }
        }
        return res;
    }

   
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss,str, ',');
        
        TreeNode *ans;
        queue<TreeNode *> q;
        
       
        ans = new TreeNode(stoi(str));
        q.push(ans);
        
      
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            getline(ss,str,','); // helps us to fetch a character before ','
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            getline(ss,str,',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return ans;        
    }