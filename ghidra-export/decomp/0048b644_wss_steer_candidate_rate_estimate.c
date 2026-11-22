// func wss_steer_candidate_rate_estimate @ 0048b644 size=1088

int wss_steer_candidate_rate_estimate(byte *param_1,int param_2,int param_3,char param_4)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint local_350;
  uint local_34c;
  undefined4 local_348;
  undefined1 local_344;
  undefined4 local_340;
  undefined1 local_33c;
  undefined1 auStack_338 [28];
  int local_31c;
  undefined1 auStack_2f8 [20];
  uint local_2e4;
  
  iVar6 = (int)param_4;
  local_340 = 0;
  local_33c = 0;
  local_348 = 0;
  local_344 = 0;
  local_350 = 0;
  local_34c = (uint)local_34c._1_3_;
  memset(auStack_2f8,0,0x2d8);
  if (param_1 == (byte *)0x0) {
    return -1;
  }
  if (param_2 == 0) {
    return -1;
  }
  if (param_3 == 0) {
    return -1;
  }
  if (wsta_roam_strategy_switch == '\0') {
    uVar1 = *(undefined2 *)(param_2 + 6);
  }
  else {
    printf("[WSTA_ROAM_STRATEGY]%s()/%d Estimate rate for [%02x:%02x:%02x:%02x:%02x:%02x] at ap[%d] rd[%d] wlan[%d].\n"
           ,"wss_steer_candidate_rate_estimate",0x308,(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5],
           (uint)*(ushort *)(param_2 + 6),(uint)*(byte *)(param_2 + 8),
           (uint)*(byte *)(param_2 + 0xd));
    uVar1 = *(undefined2 *)(param_2 + 6);
  }
  iVar2 = apmngr_db_entry_get_by_id(uVar1,auStack_2f8);
  if ((iVar2 != 0) ||
     ((((1 < local_2e4 && (local_2e4 != 3)) && (local_2e4 != 2)) &&
      (((local_2e4 != 4 && (local_2e4 != 8)) && (local_2e4 != 6)))))) {
    iVar6 = -1;
    if (wsta_roam_strategy_switch == '\0') {
      return -1;
    }
    pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d No ap entry or is not ap, set estimate rate = -1.\n";
    uVar4 = 0x30c;
    goto LAB_0048b7f8;
  }
  iVar2 = _sta_caps_calculate(param_1,*(undefined4 *)(param_3 + 4),&local_340);
  if (iVar2 == 0) {
    iVar2 = _wlan_caps_calculate(param_2,param_3,auStack_2f8,&local_348);
    if (iVar2 != 0) {
      if (wsta_roam_strategy_switch == '\0') {
        return 0;
      }
      pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate wlan_caps failed.\n";
      uVar4 = 0x317;
      goto LAB_0048b854;
    }
    iVar2 = _steer_candidate_caps_calculate(&local_350,&local_340,&local_348);
    if (iVar2 != 0) {
      if (wsta_roam_strategy_switch == '\0') {
        return 0;
      }
      pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate candidate_caps failed.\n";
      uVar4 = 0x31c;
      goto LAB_0048b854;
    }
    if ((-0x5f < iVar6) && (uVar5 = iVar6 + 0x5fU & 0xff, uVar5 != 0)) {
      if (wsta_roam_strategy_switch == '\0') {
        iVar6 = *(int *)(param_3 + 4);
      }
      else {
        printf("[WSTA_ROAM_STRATEGY]%s()/%d [rcpi:%d] [bw:%d] ==> [estimated_snr:%d]\n",
               "wss_steer_candidate_rate_estimate",0x328,iVar6,local_350 >> 0x18,uVar5);
        iVar6 = *(int *)(param_3 + 4);
      }
      iVar6 = estimate_rate_from_snr(uVar5,local_350,local_34c,iVar6 != 0);
      if (iVar6 == 0) {
        if (wsta_roam_strategy_switch == '\0') {
          return 0;
        }
        pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d Invalid estimate rate, ==> [total_rate:0Mbps]\n";
        uVar4 = 0x32e;
      }
      else {
        if (wsta_roam_strategy_switch != '\0') {
          printf("[WSTA_ROAM_STRATEGY]%s()/%d [snr:%d] [mode:%d] [nss:%d] [bw:%d] ==> [estimated_rate:%dMbps]\n"
                 ,"wss_steer_candidate_rate_estimate",0x333,uVar5,local_350 >> 8 & 0xff,
                 local_350 >> 0x10 & 0xff,local_350 >> 0x18,iVar6);
        }
        if (((local_2e4 != 4) && (local_2e4 != 8)) && (local_2e4 != 6)) {
          return iVar6;
        }
        memset(auStack_338,0,0x3c);
        iVar2 = mesh_db_ap_entry_get(*(undefined2 *)(param_2 + 6),auStack_338);
        if (iVar2 == 0) {
          iVar2 = iVar6 + local_31c;
          if (local_31c == 0) {
            if (wsta_roam_strategy_switch == '\0') {
              return 0;
            }
            printf("[WSTA_ROAM_STRATEGY]%s()/%d get re-ap rate2cap error[%u].\n",
                   "wss_steer_candidate_rate_estimate",0x342,0);
          }
          else if (iVar2 != 0) {
            if (iVar2 == 0) {
              trap(7);
            }
            iVar2 = (iVar6 * local_31c) / iVar2;
            if (wsta_roam_strategy_switch == '\0') {
              return iVar2;
            }
            printf("[WSTA_ROAM_STRATEGY]%s()/%d [estimated_rate:%dMbps] [rate2cap:%dMbps] ==> [total_rate:%dMbps]\n"
                   ,"wss_steer_candidate_rate_estimate",0x34e,iVar6,local_31c,iVar2);
            return iVar2;
          }
          goto LAB_0048b764;
        }
        if (wsta_roam_strategy_switch == '\0') {
          return 0;
        }
        pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d Get mesh entry failed.\n";
        uVar4 = 0x33d;
      }
      goto LAB_0048b854;
    }
    if (wsta_roam_strategy_switch != '\0') {
      pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d SNR is too low, ==> [total_rate:0Mbps]\n";
      uVar4 = 0x323;
      goto LAB_0048b854;
    }
  }
  else {
    if (wsta_roam_strategy_switch == '\0') goto LAB_0048b764;
    pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate sta_caps failed.\n";
    uVar4 = 0x312;
LAB_0048b854:
    printf(pcVar3,"wss_steer_candidate_rate_estimate",uVar4);
  }
LAB_0048b764:
  iVar6 = 0;
  if (wsta_roam_strategy_switch == '\0') {
    return 0;
  }
  pcVar3 = "[WSTA_ROAM_STRATEGY]%s()/%d Calculate rate error, use default value = 0.\n";
  uVar4 = 0x35b;
LAB_0048b7f8:
  printf(pcVar3,"wss_steer_candidate_rate_estimate",uVar4);
  return iVar6;
}

