// func get_estimate_by_stat @ 0048b238 size=1036

int get_estimate_by_stat(int param_1,char param_2,undefined2 param_3,byte param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint local_368;
  uint local_364;
  undefined4 local_360;
  undefined1 local_35c;
  undefined4 local_358;
  undefined1 local_354;
  undefined4 local_350;
  uint local_34c;
  int local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined1 auStack_338 [28];
  int local_31c;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  uint local_2e4;
  
  iVar5 = (int)param_2;
  local_358 = 0;
  local_354 = 0;
  local_360 = 0;
  local_35c = 0;
  local_368 = 0;
  local_364 = (uint)local_364._1_3_;
  memset(auStack_2f8,0,0x2d8);
  local_350 = 0;
  local_34c = 0;
  local_348 = 0;
  local_344 = 0;
  local_340 = 0;
  local_33c = 0;
  if (param_1 == 0) {
    return -1;
  }
  if (param_5 == 0) {
    return -1;
  }
  iVar1 = apmngr_db_entry_get_by_id(param_3,auStack_2f8);
  if (iVar1 != 0) {
LAB_0048b304:
    iVar5 = -1;
    if (wsta_roam_strategy_switch == '\0') {
      return -1;
    }
    pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d No ap entry or is not ap, set estimate rate = -1.\n";
    uVar3 = 0x2a1;
    goto LAB_0048b390;
  }
  if ((((local_2e4 < 2) || (local_2e4 == 3)) || (local_2e4 == 2)) ||
     ((local_2e4 == 4 || (local_2e4 == 8)))) {
    uVar3 = *(undefined4 *)(param_5 + 4);
  }
  else {
    if (local_2e4 != 6) goto LAB_0048b304;
    uVar3 = *(undefined4 *)(param_5 + 4);
  }
  iVar1 = _sta_caps_calculate(param_1,uVar3,&local_358);
  if (iVar1 == 0) {
    local_350 = 0;
    local_344 = 0;
    local_340 = 0;
    local_33c = 0;
    local_34c = (uint)local_2e8;
    local_348 = (uint)param_4 << 0x18;
    iVar1 = _wlan_caps_calculate(&local_350,param_5,auStack_2f8,&local_360);
    if (iVar1 == 0) {
      iVar1 = _steer_candidate_caps_calculate(&local_368,&local_358,&local_360);
      if (iVar1 == 0) {
        iVar1 = (int)*(char *)(param_5 + 0x10);
        uVar4 = iVar5 - iVar1;
        if (iVar1 == 0) {
          uVar4 = iVar5 + 0x5f;
        }
        uVar4 = uVar4 & 0xff;
        if (uVar4 == 0) {
          if (wsta_roam_strategy_switch == '\0') {
            return 0;
          }
          pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d SNR is too low, ==> [total_rate:0Mbps]\n";
          uVar3 = 699;
        }
        else {
          if (wsta_roam_strategy_switch == '\0') {
            iVar5 = *(int *)(param_5 + 4);
          }
          else {
            printf("[WSTA_ROAM_STRATEGY]%s()/%d [rcpi:%d] [bw:%d] [nf:%d] ==> [estimated_snr:%d]\n",
                   "get_estimate_by_stat",0x2c0,iVar5,local_368 >> 0x18,iVar1,uVar4);
            iVar5 = *(int *)(param_5 + 4);
          }
          iVar5 = estimate_rate_from_snr(uVar4,local_368,local_364,iVar5 != 0);
          if (iVar5 == 0) {
            if (wsta_roam_strategy_switch == '\0') {
              return 0;
            }
            pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d Invalid estimate rate, ==> [total_rate:0Mbps]\n";
            uVar3 = 0x2c5;
          }
          else {
            if (wsta_roam_strategy_switch != '\0') {
              printf("[WSTA_ROAM_STRATEGY]%s()/%d [snr:%d] [mode:%d] [nss:%d] [bw:%d] ==> [estimated_rate:%dMbps]\n"
                     ,"get_estimate_by_stat",0x2ca,uVar4,local_368 >> 8 & 0xff,
                     local_368 >> 0x10 & 0xff,local_368 >> 0x18,iVar5);
            }
            if (((local_2e4 != 4) && (local_2e4 != 8)) && (local_2e4 != 6)) {
              return iVar5;
            }
            memset(auStack_338,0,0x3c);
            iVar1 = mesh_db_ap_entry_get(local_34c & 0xffff,auStack_338);
            if (iVar1 == 0) {
              iVar1 = iVar5 + local_31c;
              if (local_31c == 0) {
                if (wsta_roam_strategy_switch == '\0') {
                  return 0;
                }
                printf("[WSTA_ROAM_STRATEGY]%s()/%d get re-ap rate2cap error[%u].\n",
                       "get_estimate_by_stat",0x2d9,0);
              }
              else if (iVar1 != 0) {
                if (iVar1 == 0) {
                  trap(7);
                }
                iVar1 = (iVar5 * local_31c) / iVar1;
                if (wsta_roam_strategy_switch == '\0') {
                  return iVar1;
                }
                printf("[WSTA_ROAM_STRATEGY]%s()/%d [estimated_rate:%dMbps] [rate2cap:%dMbps] ==> [total_rate:%dMbps]\n"
                       ,"get_estimate_by_stat",0x2e5,iVar5,local_31c,iVar1);
                return iVar1;
              }
              goto LAB_0048b35c;
            }
            if (wsta_roam_strategy_switch == '\0') {
              return 0;
            }
            pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d Get mesh entry failed.\n";
            uVar3 = 0x2d4;
          }
        }
      }
      else {
        if (wsta_roam_strategy_switch == '\0') {
          return 0;
        }
        pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate candidate_caps failed.\n";
        uVar3 = 0x2b4;
      }
    }
    else {
      if (wsta_roam_strategy_switch == '\0') {
        return 0;
      }
      pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate wlan_caps failed.\n";
      uVar3 = 0x2af;
    }
LAB_0048b410:
    printf(pcVar2,"get_estimate_by_stat",uVar3);
  }
  else if (wsta_roam_strategy_switch != '\0') {
    pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate sta_caps failed.\n";
    uVar3 = 0x2a6;
    goto LAB_0048b410;
  }
LAB_0048b35c:
  iVar5 = 0;
  if (wsta_roam_strategy_switch == '\0') {
    return 0;
  }
  pcVar2 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate rate error, use default value = 0.\n";
  uVar3 = 0x2f1;
LAB_0048b390:
  printf(pcVar2,"get_estimate_by_stat",uVar3);
  return iVar5;
}

