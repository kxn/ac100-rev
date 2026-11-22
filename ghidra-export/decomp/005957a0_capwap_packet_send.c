// func capwap_packet_send @ 005957a0 size=536

undefined4 capwap_packet_send(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x47;
    pcVar3 = "NULL != session";
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      if (*(undefined4 **)(param_1 + 0x50) == (undefined4 *)0x0) {
        if (*(char *)(param_1 + 0x1c) == '\x01') {
          iVar1 = capwap_plain_packet_send
                            (*(undefined4 *)(param_1 + 0x38),param_1 + 0x1c,param_1,*param_2,
                             *(undefined2 *)(param_2 + 1));
          if (0 < iVar1) {
            return 0;
          }
          if (capwap_warning_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar3 = "[CW_WARNING]%32s():%4d send capwap non-DTLS packet failed\n";
          uVar2 = 0x52;
        }
        else if (*(char *)(param_1 + 0x1c) == '\x02') {
          iVar1 = capwap_plain_ipv6_packet_send
                            (*(undefined4 *)(param_1 + 0x38),param_1 + 0x1c,param_1,*param_2,
                             *(undefined2 *)(param_2 + 1));
          if (0 < iVar1) {
            return 0;
          }
          if (capwap_warning_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar3 = "[CW_WARNING]%32s():%4d send capwap non-DTLS packet failed\n";
          uVar2 = 0x5a;
        }
        else {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar3 = "[CW_ERROR]%32s():%4d Illegal ip type\n";
          uVar2 = 0x60;
        }
      }
      else {
        iVar1 = gnutls_record_send(**(undefined4 **)(param_1 + 0x50),*param_2,
                                   *(undefined2 *)(param_2 + 1));
        if (0 < iVar1) {
          return 0;
        }
        iVar1 = gnutls_record_send(**(undefined4 **)(param_1 + 0x50),*param_2,
                                   *(undefined2 *)(param_2 + 1));
        if (0 < iVar1) {
          return 0;
        }
        if (capwap_warning_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar3 = "[CW_WARNING]%32s():%4d send capwap DTLS packet failed\n";
        uVar2 = 0x6a;
      }
      printf(pcVar3,"capwap_packet_send",uVar2);
      return 0xffffffff;
    }
    uVar2 = 0x48;
    pcVar3 = "NULL != pkt_buff";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_packet_send",uVar2,pcVar3);
  return 0xffffffff;
}

