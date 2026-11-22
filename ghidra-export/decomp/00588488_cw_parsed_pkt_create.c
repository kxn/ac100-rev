// func cw_parsed_pkt_create @ 00588488 size=256

int cw_parsed_pkt_create(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 - 1U < 0x1a) || (param_1 - 0x33dd01U < 2)) {
    iVar2 = cw_parsed_pkt_init();
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d create a parsed packet failed\n","cw_parsed_pkt_create",0x586);
      }
    }
    else {
      *(int *)(iVar2 + 0x10) = param_1;
      *(undefined2 *)(iVar2 + 0x16) = 3;
      cw_header_init(iVar2,1,1);
    }
  }
  else {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d invalid message type[%d]\n","cw_parsed_pkt_create",0x580,param_1)
      ;
    }
  }
  return iVar2;
}

