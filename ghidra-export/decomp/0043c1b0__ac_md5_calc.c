// func _ac_md5_calc @ 0043c1b0 size=128

void _ac_md5_calc(uchar *param_1,void *param_2,size_t param_3)

{
  MD5_CTX MStack_78;
  
  MD5_Init(&MStack_78);
  MD5_Update(&MStack_78,param_2,param_3);
  MD5_Final(param_1,&MStack_78);
  return;
}

