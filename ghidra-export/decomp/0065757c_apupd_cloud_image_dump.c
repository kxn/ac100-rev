// func apupd_cloud_image_dump @ 0065757c size=444

void apupd_cloud_image_dump(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined1 auStack_60 [36];
  undefined1 auStack_3c [40];
  
  memset(auStack_3c,0,0x21);
  memset(auStack_60,0,0x21);
  if ((param_1 != 0) && (g_apupd_debug != 0)) {
    puts("------------apupd_cloud_image_dump----------");
    FUN_004084f0(param_1,0x10,auStack_3c);
    printf("vendor id : %d \n",(uint)*(ushort *)(param_1 + 0x10));
    printf("zone code : %d \n",(uint)*(ushort *)(param_1 + 0x12));
    printf("ras status : %d \n",(uint)*(byte *)(param_1 + 0x1ac));
    printf("software version: %s \n",param_1 + 0x14);
    printf("firmware id : %s \n",auStack_3c);
    printf("hardware id list(total=%d): ",(uint)*(ushort *)(param_1 + 0x48));
    uVar1 = *(ushort *)(param_1 + 0x48);
    for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
      FUN_004084f0(param_1 + iVar2 * 0x10 + 0x4c,0x10,auStack_60);
      printf("\t%s",auStack_60);
      uVar1 = *(ushort *)(param_1 + 0x48);
    }
    putchar(10);
    printf("fl firmware id list(total=%d): ",(uint)*(ushort *)(param_1 + 0x4a));
    uVar1 = *(ushort *)(param_1 + 0x4a);
    for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
      memset(auStack_3c,0,0x21);
      FUN_004084f0(param_1 + iVar2 * 0x10 + 0x8c,0x10,auStack_3c);
      printf("\t%s\n",auStack_3c);
      uVar1 = *(ushort *)(param_1 + 0x4a);
    }
    putchar(10);
    puts("--------------------------------------------");
  }
  return;
}

