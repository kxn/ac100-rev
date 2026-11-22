// func cw_frag_mngr_free @ 0059672c size=164

undefined4 cw_frag_mngr_free(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_frag_mngr_free",0x32e,"NULL != session");
    uVar2 = 0xffffffff;
  }
  else {
    cw_frag_mngr_frag_free();
    while (iVar1 = FUN_004081b0(param_1 + 0x30), iVar1 != 0) {
      FUN_00408500(iVar1);
      cw_pkt_buf_destroy(*(undefined4 *)(iVar1 + 0xc));
      FUN_00407df0(iVar1);
    }
    FUN_0051ad88(param_1 + 0x30);
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return uVar2;
}

