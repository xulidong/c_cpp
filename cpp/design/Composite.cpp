#include <iostream>
#include <list>

/*
 * 组合模式
 * 让单个对象和组合对象具有一致的接口
 * */

using namespace std;

class IFile {
	public:
		virtual ~IFile() {}
		virtual void display() = 0;
		virtual int add(IFile* iFile) = 0;
		virtual int remove(IFile* iFile) = 0;
		virtual list<IFile*>* getChild() = 0;
};

class File: public IFile {
	public:
		File(string name) {
			m_name = name;
		}
		virtual void display() {
			cout << m_name << endl;	
		} 
		virtual int add(IFile* iFile) {
			return -1;	
		}
		virtual int remove(IFile* iFile) {
			return -1;	
		}
		virtual list<IFile*>* getChild() {
			return NULL;	
		}
	private:
		string m_name;
};

class Folder: public IFile {
	public:
		Folder(string name) {
			m_name = name;
			m_list = new list<IFile*>;
			m_list->clear();
		}
		virtual ~Folder() {
			if (m_list != NULL) {
				delete m_list;
				m_list = NULL;
			}
		}
		virtual void display() {
			cout << m_name << ":" << endl;	
		} 
		virtual int add(IFile* iFile) {
			m_list->push_back(iFile);
			return 0;
		}
		virtual int remove(IFile* iFile) {
			m_list->remove(iFile);
			return 0;
		}
		virtual list<IFile*>* getChild() {
			return m_list;
		}
	private:
		string m_name;
		list<IFile*>* m_list;
};

// 递归显示树
void showTree(IFile* root, int level) {
	if (root == NULL) {
		return;
	}

	for(int i = 0; i < level; ++i) {
		cout << "\t";
	}

	// 1 显示根节点
	root->display();

	list<IFile*>* mylist = root->getChild();

	// 2 若子节点为文件，直接显示文件名
	if (mylist == NULL) {
		return;	
	} else {
	// 3 若子节点为文件夹，则递归调用
		for(list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); ++it) {
			if ((*it)->getChild() == NULL) {
				for(int i = 0; i < level + 1; ++i) {
					cout << "\t";
				}
				(*it)->display();	
			} else {
				showTree(*it, level + 1);
			}
		}
	
	}
}

int main() {
	Folder* root = new Folder("C");

	File* file1 = new File("file1.txt");
	root->add(file1);

	Folder* folder1 = new Folder("folder1");
	File* file2 = new File("file2.txt");
	folder1->add(file2);
	root->add(folder1);

	showTree(root, 0);

	delete file1;
	delete folder1;
	delete root;

	return 0;
}
