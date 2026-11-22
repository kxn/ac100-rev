// func FUN_00414ea8 @ 00414ea8 size=764

undefined4 FUN_00414ea8(undefined4 *param_1,int param_2,char *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  short sVar5;
  undefined4 uVar4;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char local_260 [240];
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_148;
  undefined4 local_144;
  uint *local_140;
  uint *local_13c;
  uint local_138;
  char acStack_134 [128];
  uint local_b4;
  char acStack_b0 [128];
  char local_30;
  undefined1 auStack_2c [12];
  
  local_148 = 0;
  local_144 = 0;
  local_140 = (uint *)0x0;
  local_13c = (uint *)0x0;
  uVar1 = rdmngr_db_generate_ap_id(*param_1);
  memset(&local_b4,0,0x94);
  local_260[0] = '\0';
  local_260[1] = '\0';
  local_260[2] = '\0';
  local_260[3] = 'd';
  snprintf(acStack_b0,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
           g_portal_port);
  local_b4 = (uint)*(ushort *)(param_2 + 0x1f8);
  FUN_0051ad88(auStack_2c);
  sVar5 = *(short *)(param_2 + 0x1f8);
  if (sVar5 == 0xfff) {
    sVar5 = 0;
  }
  uac_wservice_for_ap_bind_vlan(sVar5,uVar1,_wportal_collect_ssid_info_cb,auStack_2c);
  local_30 = FUN_00407fe0(auStack_2c);
  local_144 = 0x1a;
  if (local_30 != '\0') {
    local_144 = 0x19;
  }
  local_13c = &local_b4;
  memset(&local_138,0,0x84);
  local_260[0] = '\0';
  local_260[1] = '\0';
  local_260[2] = '\0';
  local_260[3] = 'd';
  snprintf(acStack_134,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
           g_portal_port);
  local_138 = (uint)*(ushort *)(param_2 + 0x1f8);
  local_148 = 2;
  local_140 = &local_138;
  _wportal_update_wportal_cb(uVar1,&local_148);
  uVar2 = 0;
  if (*param_3 == '\0') {
    cVar3 = param_3[0x80];
  }
  else {
    for (; uVar2 < 0x80; uVar2 = uVar2 + 1) {
      local_260[uVar2 + 0x70] = param_3[uVar2 + 0x80];
    }
    local_170 = *(undefined4 *)(param_3 + 0x154);
    local_16c = *(undefined4 *)(param_3 + 0x158);
    local_168 = *(undefined4 *)(param_3 + 0x15c);
    local_160 = 1;
    local_15c = 2;
    local_158 = 0xffffffff;
    uVar4 = *(undefined4 *)param_3;
    uVar6 = *(undefined4 *)(param_3 + 4);
    uVar7 = *(undefined4 *)(param_3 + 8);
    uVar8 = *(undefined4 *)(param_3 + 0xc);
    for (uVar2 = 0; uVar2 < 0x70; uVar2 = uVar2 + 1) {
      local_260[uVar2] = param_3[uVar2 + 0x10];
    }
    local_164 = uVar1;
    FUN_00413e94(uVar4,uVar6,uVar7,uVar8);
    cVar3 = param_3[0x80];
  }
  if (cVar3 != '\0') {
    for (uVar2 = 0; uVar2 < 0x80; uVar2 = uVar2 + 1) {
      local_260[uVar2 + 0x70] = param_3[uVar2 + 0x80];
    }
    local_170 = *(undefined4 *)(param_3 + 0x154);
    local_16c = *(undefined4 *)(param_3 + 0x158);
    local_168 = *(undefined4 *)(param_3 + 0x15c);
    local_160 = 2;
    local_15c = 2;
    local_158 = 0xffffffff;
    uVar4 = *(undefined4 *)param_3;
    uVar6 = *(undefined4 *)(param_3 + 4);
    uVar7 = *(undefined4 *)(param_3 + 8);
    uVar8 = *(undefined4 *)(param_3 + 0xc);
    for (uVar2 = 0; uVar2 < 0x70; uVar2 = uVar2 + 1) {
      local_260[uVar2] = param_3[uVar2 + 0x10];
    }
    local_164 = uVar1;
    FUN_00413e94(uVar4,uVar6,uVar7,uVar8);
  }
  return 0;
}

