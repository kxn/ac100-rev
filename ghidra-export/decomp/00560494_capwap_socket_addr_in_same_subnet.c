// func capwap_socket_addr_in_same_subnet @ 00560494 size=324

bool capwap_socket_addr_in_same_subnet(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  if (((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) || (param_3 == (char *)0x0)) {
    if (capwap_err_switch == 0) {
      return false;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return false;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d Illegal input\n";
    uVar6 = 0x5e;
  }
  else {
    if ((*param_2 == *param_1) && (cVar1 = *param_3, cVar1 == *param_2)) {
      if (cVar1 == '\x01') {
        return ((*(uint *)(param_2 + 4) ^ *(uint *)(param_1 + 4)) & *(uint *)(param_3 + 4)) == 0;
      }
      if (cVar1 == '\x02') {
        iVar4 = 0;
        pcVar5 = param_3;
        while( true ) {
          if (pcVar5[4] == 0) {
            return true;
          }
          iVar2 = iVar4 + 4;
          iVar3 = iVar4 + 4;
          iVar4 = iVar4 + 1;
          if ((byte)(pcVar5[4] & (param_2[iVar2] ^ param_1[iVar3])) != 0) break;
          if (iVar4 == 0x10) {
            return true;
          }
          pcVar5 = param_3 + iVar4;
        }
        return false;
      }
      return false;
    }
    if (capwap_err_switch == 0) {
      return false;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return false;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d ip_type is not same\n";
    uVar6 = 99;
  }
  printf(pcVar5,"capwap_socket_addr_in_same_subnet",uVar6);
  return false;
}

