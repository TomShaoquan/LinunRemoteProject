#ifndef QINTU_LARGEFILE_MMAPFILE_H
#define QINTU_LARGEFILE_MMAPFILE_H


#include"common.h"

namespace qiniu
{
	namespace largefile
	{
		class MMapFile
		{
		public:
			MMapFile();  ////Ĭ�Ϲ���
			~MMapFile();
			explicit MMapFile(const int fd);		
			MMapFile(const MMapOption& mmap_option, const int fd);
			//ͬ���ļ�
			bool sync_file();						
			//���ļ�ӳ�䵽�ڴ�,ͬʱ���÷���Ȩ��
			bool map_file(const bool write=false);	
			//��ȡӳ�䵽�ڴ�����ݵ��׵�ַ
			void* get_data() const;	
			//��ȡӳ�����ݵĴ�С
			int32_t get_size() const;				
			//���ӳ��
			bool munmap_file();
			//����ӳ��
			bool remap_file();						
			
		private:
			//ӳ����ڴ��������  size �ڴ�ӳ���С
			bool ensure_file_size(const int32_t size);
			
		private:
			//ӳ��Ĵ�С
			int32_t size_;		
			int fd_;			//�ļ����
			void* data_;		//���ݵ�ַ
			struct MMapOption mmap_file_option_;
		};

	}
}
#endif // !QINTU_LARGEFILE_MMAPFILE_H

