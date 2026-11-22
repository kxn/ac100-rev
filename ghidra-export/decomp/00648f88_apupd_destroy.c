// func apupd_destroy @ 00648f88 size=112

undefined4 apupd_destroy(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = apupd_db_destroy();
  if (((iVar1 == -1) && (uVar2 = 0xffffffff, g_apupd_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: apupd db destory failed.\r\n","apupd_destroy",0x12f7);
  }
  return uVar2;
}

