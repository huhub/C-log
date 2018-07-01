#ifndef _LOG_H_
#define _LOG_H_

#define LOG_SUCCESS	0
#define LOG_FAILED	-1

#define RUN_LEVEL (0)    /*���м���0ȫ�����1����澯�ʹ���2�������3ȫ�����*/

#define MAX_FILE_SIZE (1024*1024*2)    /*��־�ļ���С�������*/

#define MBUF_MAX 160    /*��������ַ�������*/

#define RUN_LOG_PATH "run_log.log"    /*��־�ļ�·��*/

#define RUN_LOG_BAK_PATH "run_log_bak.log"    /*������־�ļ�·��*/

#define END ""    /*�ɱ��ĩβ��ʶ*/

#define IOBUF_SIZE	1024	/*����дIO�����С*/

/*���м���*/
#define LOG_DEBUG	   0
#define LOG_RUN        1
#define LOG_WARNING    2
#define LOG_ERROR	   3

/*�Ƿ��кţ����ڷǵ��Դ�ӡ����*/
#define INVAILD_LINE_NUM	-1

/*��־��ӡ����ӿڣ����˴�ӡ,level:LOG_LEVEL*/
#define write_log(level, ...) do { \
	if (level - RUN_LEVEL < 0)	\
		break; \
	if (level == LOG_DEBUG)	\
		run_log(__LINE__, __FILE__, __VA_ARGS__, END);	\
   	else	\
   		run_log(INVAILD_LINE_NUM, __VA_ARGS__, END); \
    } while(0)

/* ��־��ӡ�ڲ��ӿڣ�����в���������ַ���������ᷢ���ض� */
void run_log(int line_num, ...);

#endif	/*!_LOG_H_*/