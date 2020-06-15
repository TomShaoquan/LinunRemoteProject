#ifndef _FILE_OP_H
#define _FILE_OP_H
#include"common.h"
#include <fcntl.h>

namespace qiniu
{
	namespace largefile
	{
		class FileOperation
		{
		public:
			FileOperation(const std::string& file_name, const int open_flags = O_RDWR|O_LARGEFILE);
			~FileOperation();

			//���ļ�
			int open_file();
			//�ر��ļ�
			void close_file();
			//���ļ����ڴ�����д����� 
			int flush_file();
			//ɾ���ļ�
			int unlink_file();
			//��ȡ�ļ�
			virtual int pread_file(char* buf, const int32_t nbytes, const int64_t offset);
			//д�ļ�
			virtual int pwrite_file(const char* buf, const int32_t nbytes, const int64_t offset);
			//�ڵ�ǰ��λ��д
			int write_file(char* buf, const int32_t nbytes);
			//��ȡ�ļ���С
			int64_t get_file_size();
			//�ı��ļ���С
			int ftruncate_file(const int64_t length);
			//�ƶ��ļ�ָ��
			int seek_file(const int64_t offset);
			//�ļ����
			int get_fd() const {
				return fd_;
			}
		protected:
			int check_file();
		protected:
			int fd_;
			//Ȩ��
			int open_flags;
			//�ļ���
			char* file_name_;
		protected:
			//��Ȩ��
			static const mode_t OPEN_MODE = 0644;
			//����ȡ����
			static const int MAX_DISK_TIMES = 5;	
		};

	}
}

#endif // !_FILE_OP_H



