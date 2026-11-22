// func capwap_socket_ifindex_to_addr @ 005605d8 size=1044

undefined4
capwap_socket_ifindex_to_addr
          (uint param_1,int param_2,uint param_3,undefined1 *param_4,undefined1 *param_5)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  byte bVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  void *__cp;
  undefined4 *local_90;
  undefined1 auStack_8c [16];
  uint local_7c;
  undefined4 local_78;
  char acStack_6c [68];
  
  if (param_2 == 0) {
    local_7c = param_3;
    iVar1 = ioctl(param_1,0x8910,auStack_8c);
    if (iVar1 == 0) {
      if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_DEBUG]%32s():%4d ifindex %d responds to addr %s.\n",
               "capwap_socket_ifindex_to_addr",0xb5,param_3,auStack_8c);
      }
      iVar1 = ioctl(param_1,0x8915,auStack_8c);
      if (iVar1 == 0) {
        *param_4 = 1;
        *(undefined4 *)(param_4 + 4) = local_78;
        iVar1 = ioctl(param_1,0x891b,auStack_8c);
        if (iVar1 == 0) {
          *param_5 = 1;
          *(undefined4 *)(param_5 + 4) = local_78;
          if (capwap_debug_switch == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          printf("[CW_DEBUG]%32s():%4d ifindex %d responds to addr %s.\n",
                 "capwap_socket_ifindex_to_addr",199,param_3,acStack_6c);
          return 0;
        }
        if (capwap_warning_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[CW_WARNING]%32s():%4d get if_index %d\'s netmask error\n";
        uVar6 = 0xc2;
      }
      else {
        if (capwap_warning_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[CW_WARNING]%32s():%4d get if_index %d\'s ipaddr error\n";
        uVar6 = 0xb9;
      }
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[CW_ERROR]%32s():%4d get if_index %d\'s name error\n";
      uVar6 = 0xb2;
    }
  }
  else if ((int)param_1 < 0) {
    if (capwap_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[CW_WARNING]%32s():%4d socket(%d) illegal\n";
    uVar6 = 0x89;
    param_3 = param_1;
  }
  else {
    iVar1 = getifaddrs(&local_90);
    if (iVar1 == -1) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d getifaddrs failed\n","capwap_socket_ifindex_to_addr",0x8e);
      return 0xffffffff;
    }
    puVar7 = local_90;
    if (local_90 != (undefined4 *)0x0) {
      psVar2 = (short *)local_90[3];
      do {
        if (psVar2 == (short *)0x0) {
          puVar7 = (undefined4 *)*puVar7;
        }
        else {
          pcVar5 = (char *)puVar7[1];
          if (pcVar5 == (char *)0x0) {
            puVar7 = (undefined4 *)*puVar7;
          }
          else if (*psVar2 == 10) {
            iVar1 = strcmp(pcVar5,"lo");
            if (iVar1 == 0) {
              puVar7 = (undefined4 *)*puVar7;
            }
            else {
              uVar3 = if_nametoindex(pcVar5);
              if (param_3 == uVar3) {
                bVar4 = *(byte *)(puVar7[3] + 8) & 0xf0;
                if ((bVar4 == 0x20) || (bVar4 == 0x30)) {
                  __cp = (void *)(puVar7[3] + 8);
                  inet_ntop(10,__cp,acStack_6c,0x14);
                  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    printf("[CW_DEBUG]%32s():%4d ifindex %d responds to addr %s.\n",
                           "capwap_socket_ifindex_to_addr",0x9d,param_3,acStack_6c);
                  }
                  memcpy(param_4 + 4,__cp,0x10);
                  *param_4 = 2;
                  memcpy(param_5 + 4,(void *)(puVar7[4] + 8),0x10);
                  *param_5 = 2;
                  break;
                }
                puVar7 = (undefined4 *)*puVar7;
              }
              else {
                puVar7 = (undefined4 *)*puVar7;
              }
            }
          }
          else {
            puVar7 = (undefined4 *)*puVar7;
          }
        }
        if (puVar7 == (undefined4 *)0x0) break;
        psVar2 = (short *)puVar7[3];
      } while( true );
    }
    freeifaddrs(local_90);
    if (puVar7 != (undefined4 *)0x0) {
      return 0;
    }
    if (capwap_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[CW_WARNING]%32s():%4d get if_index %d\'s ipaddr error\n";
    uVar6 = 0xa8;
  }
  printf(pcVar5,"capwap_socket_ifindex_to_addr",uVar6,param_3);
  return 0xffffffff;
}

