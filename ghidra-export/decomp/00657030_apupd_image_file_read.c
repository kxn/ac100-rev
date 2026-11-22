// func apupd_image_file_read @ 00657030 size=252

size_t apupd_image_file_read(char *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  FILE *__stream;
  size_t sVar2;
  char *__format;
  undefined4 uVar3;
  
  if (((param_1 == (char *)0x0) || (param_2 == (void *)0x0)) || (param_3 == 0)) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar3 = 0x21e2;
      goto LAB_006570e4;
    }
  }
  else {
    __stream = fopen(param_1,"r");
    if (__stream != (FILE *)0x0) {
      sVar2 = fread(param_2,1,param_3,__stream);
      fclose(__stream);
      return sVar2;
    }
    if (g_apupd_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: open image file failed.\r\n";
      uVar3 = 0x21e9;
LAB_006570e4:
      printf(__format,"apupd_image_file_read",uVar3);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

