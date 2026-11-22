// func wsta_roam_chnl_handle @ 00486aa8 size=716

void wsta_roam_chnl_handle(int param_1)

{
  int iVar1;
  undefined4 *__s;
  undefined4 *puVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 local_308 [2];
  undefined1 auStack_300 [732];
  
  memset(auStack_300,0,0x2d8);
  local_308[0] = 0;
  iVar1 = get_acs_process_state();
  if (iVar1 == 1) {
    if ((param_1 == 0) || (__s = (undefined4 *)FUN_00408450(0x61c,0x8e9), __s == (undefined4 *)0x0))
    {
      init_acs_to_end_state();
    }
    else {
      memset(__s,0,0x61c);
      iVar1 = 0;
      puVar2 = __s;
      do {
        iVar1 = iVar1 + 1;
        *puVar2 = 0xffffffff;
        puVar2[0xc1] = 0xffffffff;
        puVar2 = puVar2 + 1;
      } while (iVar1 != 0xc1);
      *(undefined2 *)(__s + 0x185) = 0xffff;
      *(undefined2 *)((int)__s + 0x616) = 0xffff;
      *(undefined2 *)(__s + 0x186) = 0xffff;
      iVar10 = 0;
      FUN_004082d0(wsta_roam_pkt_chnl_mutex,0xffffffff);
      uVar3 = acs_ap_cnt;
      FUN_00407f30(wsta_roam_pkt_chnl_mutex);
      __s[0x182] = uVar3;
      init_acs_to_end_state();
      uVar3 = FUN_00407fe0(param_1);
      __s[0x183] = uVar3;
      __s[0x184] = 0;
      iVar1 = FUN_004081b0(param_1);
      if (iVar1 != 0) {
        iVar8 = *(int *)(iVar1 + 0xc);
        while( true ) {
          if (((iVar8 != 0) && (pbVar9 = *(byte **)(iVar8 + 0x18), pbVar9 != (byte *)0x0)) &&
             (*pbVar9 != 0)) {
            memset(auStack_300,0,0x2d8);
            iVar8 = apmngr_db_entry_get_by_mac(iVar8 + 0x12,auStack_300);
            iVar5 = 0;
            if (iVar8 == 0) {
              while (iVar5 < (int)(uint)*pbVar9) {
                pbVar4 = (byte *)(*(int *)(pbVar9 + 4) + iVar5 * 8);
                if (pbVar4[3] == 1) {
                  __s[0x184] = 1;
                }
                if (*pbVar4 < 0xc1) {
                  uVar7 = __s[*pbVar4];
                  uVar6 = (uint)pbVar4[1];
                  if (uVar7 != 0xffffffff) {
                    uVar6 = uVar7 + uVar6;
                  }
                  __s[*pbVar4] = uVar6;
                  uVar6 = (uint)*pbVar4;
                  if (__s[uVar6] == -1) {
                    iVar5 = iVar5 + 1;
                    __s[uVar6 + 0xc1] = (uint)pbVar4[2];
                  }
                  else {
                    __s[uVar6 + 0xc1] = __s[uVar6 + 0xc1] + (uint)pbVar4[2];
                    iVar5 = iVar5 + 1;
                  }
                }
                else {
                  iVar5 = iVar5 + 1;
                }
              }
              iVar10 = iVar10 + 1;
            }
            else if (wsta_roam_warning_switch != '\0') {
              printf("[WSTA_ROAM_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
                     "wsta_roam_chnl_handle",0x908);
            }
          }
          iVar1 = FUN_00408680(iVar1);
          if (iVar1 == 0) break;
          iVar8 = *(int *)(iVar1 + 0xc);
        }
      }
      __s[0x183] = iVar10;
      iVar1 = FUN_004084e0(local_308,"wsta_roam_chnl_handle_thread",wsta_roam_chnl_handle_thread,__s
                          );
      if (iVar1 != 0) {
        FUN_00407df0(__s);
      }
    }
  }
  else {
    init_acs_to_end_state();
    FUN_004084e0(local_308,"wsta_roam_chnl_handle_thread",wsta_roam_chnl_handle_thread,0);
  }
  return;
}

