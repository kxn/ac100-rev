// func apupd_cloud_image_file_check @ 0065712c size=160

undefined4 apupd_cloud_image_file_check(int param_1,void *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    uVar1 = *(ushort *)(param_1 + 0x10);
    uVar2 = FUN_00408080();
    iVar4 = 0;
    if (uVar1 == uVar2) {
      uVar1 = *(ushort *)(param_1 + 0x48);
      while (iVar4 < (int)(uint)uVar1) {
        iVar3 = memcmp((void *)(param_1 + iVar4 * 0x10 + 0x4c),param_2,0x10);
        iVar4 = iVar4 + 1;
        if (iVar3 == 0) {
          return 0;
        }
        uVar1 = *(ushort *)(param_1 + 0x48);
      }
    }
  }
  return 0xffffffff;
}

