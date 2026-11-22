// func apupd_image_size_get @ 00657004 size=44

__blkcnt_t apupd_image_size_get(char *param_1)

{
  int iVar1;
  stat sStack_a0;
  
  iVar1 = stat(param_1,&sStack_a0);
  if (iVar1 < 0) {
    sStack_a0.st_blocks = 0;
  }
  return sStack_a0.st_blocks;
}

