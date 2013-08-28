class CMemDC:public CDC   //�����ڴ滭��
{
private:
	CBitmap*  m_pbmp;           // ����λͼ����ָ��
	CBitmap*  m_poldbmp;         //����λͼ����ָ��
	CDC*      m_pDC;            //�����豸������ָ��
	CRect     m_Rect;           //�����������



public:
	CMemDC(CDC* pDC, const CRect& rect):CDC(){                           //���캯��
		CreateCompatible(pDC);                                      //����һ�����ݵ��豸������
		
		m_pbmp = new CBitmap;                                                           //����λͼ����
        m_poldbmp->CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());  //����λͼ
		m_poldbmp =SelectObject(m_pbmp);                                //ѡ��λͼ����
	    m_pDC = pDC;                                               //���ó�Ա����
		m_Rect = rect;

	                       	//��Ŀ������������ڴ滭����
		this->BitBlt(m_Rect.left,m_Rect.top,m_Rect.Width(),m_Rect.Height(),pDC,m_Rect.left,m_Rect.top,SRCCOPY);
	}

	~CMemDC(){
                               //���ڴ滭���ͷ�ʱ���ڴ滭�������ݻ�����Ŀ��������
		m_pDC->BitBlt(m_Rect.left,m_Rect.top,m_Rect.Width(),m_Rect.Height(),this,m_Rect.left,m_Rect.top,SRCCOPY);
		SelectObject(m_poldbmp);  //ѡ��֮ǰѡ�е�λͼ����
		if (m_poldbmp != NULL)   //�ж�λͼ�����Ƿ�Ϊ��
		{
			delete m_poldbmp;      //�ͷ�λͼ����
		}
		DeleteObject(this);  //�ͷ��豸������
	}
};