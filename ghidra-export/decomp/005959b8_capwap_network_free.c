// func capwap_network_free @ 005959b8 size=176

undefined4 capwap_network_free(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_network_free",0xf5,"NULL != session");
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) {
      capwap_dtls_data_destroy();
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
    while (iVar1 = FUN_004081b0(param_1 + 0x58), iVar1 != 0) {
      cw_pkt_buf_destroy(*(undefined4 *)(iVar1 + 0xc));
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    uVar2 = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return uVar2;
}

