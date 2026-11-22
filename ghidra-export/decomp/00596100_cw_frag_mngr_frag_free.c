// func cw_frag_mngr_frag_free @ 00596100 size=212

void cw_frag_mngr_frag_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1 + 0x14), iVar1 != 0) {
      FUN_00408500(iVar1);
      cw_pkt_buf_destroy(*(undefined4 *)(iVar1 + 0xc));
      FUN_00407df0(iVar1);
    }
    FUN_0051ad88(param_1 + 0x14);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x10) = 0;
    if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_1 + 0x20) != 0)) {
      cw_timer_remove();
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_frag_mngr_frag_free",0x89,"NULL != session");
  return;
}

