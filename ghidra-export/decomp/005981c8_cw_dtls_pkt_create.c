// func cw_dtls_pkt_create @ 005981c8 size=1

int cw_dtls_pkt_create(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00408450(0x10,100);
  if (iVar1 == 0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory.\n","cw_dtls_pkt_create",0x66);
    }
  }
  else {
    FUN_0051ad88(iVar1 + 4);
  }
  return iVar1;
}

