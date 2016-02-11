
/*
LintCode: assignment operator overloading C only
http://www.lintcode.com/zh-cn/problem/assignment-operator-overloading-c-only/
*/


class Solution {
	public:
		char *m_pData;
		Solution() {
			this->m_pData = NULL;
		}
		Solution(char *pData) {
			this->m_pData = pData;
		}
		Solution operator=(const Solution &object) {
			if(this == &object) {
				return *this;
			}
			if(this->m_pData) {
				delete []m_pData;
				m_pData = NULL;
			}
			if(object.m_pData) {
				m_pData = new char[strlen(object.m_pData)+1];
				strcpy(m_pData, object.m_pData);
			}
			return *this;
		}
}
