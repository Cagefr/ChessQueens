class StackNode{
	private:
		int row;
		int col;
		StackNode *next;
		
	public:
		StackNode(){row=-1,col=-1; next=nullptr;}
		StackNode(int r, int c, StackNode * n){row=r;col=c;next = n;}
		void setNext(StackNode *n){next = n;}
		void setRow(int r){ row=r;}
		void setCol(int c){ col=c;}

		StackNode *getNext(){return next;}
		int getRow(){return row;}
		int getCol(){return col;}
		void printInfo();
};

void StackNode::printInfo()
{
	cout << fixed << setprecision(2) << showpoint;
	cout << "\n\t\t\tRow : " << row << endl;
	cout << "\n\t\t\tCol : " << col << endl;
}

StackNode *createNode(int row, int col)
{      
        StackNode *node;

        try{    
                node = new StackNode(row,col,nullptr);
                //node->printInfo();
        }
        catch(bad_alloc){
                cout << "\n\n\t\t\tYikes! Out of memory!!!\n";
                node = nullptr;
        }

        return node;
}
