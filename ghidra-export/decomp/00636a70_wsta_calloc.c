// func wsta_calloc @ 00636a70 size=232

int wsta_calloc(int param_1,int param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004082a0(param_1,param_2,0x113);
  if (iVar1 != 0) {
    l_wsta_mem_stat = param_2 * param_1 + l_wsta_mem_stat;
    if (((g_wsta_mem_record_sw != 0) && (param_3 != (char *)0x0)) &&
       (iVar2 = FUN_004082a0(1,0x5c,0x11a), iVar2 != 0)) {
      *(int *)(iVar2 + 0x10) = param_2 * param_1;
      *(int *)(iVar2 + 0xc) = iVar1;
      *(undefined4 *)(iVar2 + 0x54) = param_4;
      strncpy((char *)(iVar2 + 0x14),param_3,0x3f);
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      FUN_004086b0(&wsta_mem_record,iVar2);
      FUN_00407f30(DAT_007cc6bc);
    }
  }
  return iVar1;
}

