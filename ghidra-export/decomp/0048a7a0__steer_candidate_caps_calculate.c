// func _steer_candidate_caps_calculate @ 0048a7a0 size=392

undefined4 _steer_candidate_caps_calculate(byte *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  
  uVar6 = 0xffffffff;
  if (((param_1 != (byte *)0x0) && (param_2 != (byte *)0x0)) && (param_3 != (byte *)0x0)) {
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d BSS Candidate Capability: [nss:%d] [mode:%d] [bw:%d] [mcs:%d]\n"
             ,"_steer_candidate_caps_calculate",0x283,(uint)param_3[1],(uint)param_3[2],
             (uint)*param_3,(uint)param_3[3]);
    }
    if (wsta_roam_strategy_switch == '\0') {
      bVar4 = *param_2;
    }
    else {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d STA Capability: [nss:%d] [mode:%d] [bw:%d] [mcs:%d]\n",
             "_steer_candidate_caps_calculate",0x285,(uint)param_2[1],(uint)param_2[2],
             (uint)*param_2,(uint)param_2[3]);
      bVar4 = *param_2;
    }
    bVar3 = *param_3;
    if (bVar4 < *param_3) {
      bVar3 = bVar4;
    }
    *param_1 = bVar3;
    bVar4 = param_3[2];
    if (param_2[2] < param_3[2]) {
      bVar4 = param_2[2];
    }
    param_1[2] = bVar4;
    cVar2 = wsta_roam_strategy_switch;
    bVar5 = param_3[1];
    if (param_2[1] < param_3[1]) {
      bVar5 = param_2[1];
    }
    param_1[1] = bVar5;
    uVar6 = 0;
    bVar1 = param_2[3];
    param_1[3] = bVar1;
    if (cVar2 != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Min Candidate Capability: [nss:%d] [mode:%d] [bw:%d] [mcs:%d]\n"
             ,"_steer_candidate_caps_calculate",0x28d,(uint)bVar5,(uint)bVar4,(uint)bVar3,
             (uint)bVar1);
    }
  }
  return uVar6;
}

