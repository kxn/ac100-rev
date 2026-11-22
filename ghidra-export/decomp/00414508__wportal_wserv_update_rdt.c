// func _wportal_wserv_update_rdt @ 00414508 size=984

undefined4 _wportal_wserv_update_rdt(undefined4 *param_1,int param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  void *__s;
  short sVar6;
  undefined4 uVar5;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char local_278 [240];
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  uint *local_14c;
  uint *local_148;
  uint local_144;
  char acStack_140 [128];
  uint local_c0;
  char acStack_bc [128];
  char local_3c;
  undefined1 auStack_38 [20];
  
  uVar1 = 0xffffffff;
  local_160 = 0;
  local_15c = 0;
  local_158 = 0;
  if (param_3 != (char *)0x0) {
    local_154 = 0;
    local_150 = 0;
    local_14c = (uint *)0x0;
    local_148 = (uint *)0x0;
    uVar1 = rdmngr_db_generate_ap_id(*param_1);
    memset(&local_c0,0,0x94);
    local_278[0] = '\0';
    local_278[1] = '\0';
    local_278[2] = '\0';
    local_278[3] = 'd';
    snprintf(acStack_bc,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
             g_portal_port);
    local_c0 = (uint)*(ushort *)(param_2 + 0x1f8);
    FUN_0051ad88(auStack_38);
    sVar6 = *(short *)(param_2 + 0x1f8);
    if (sVar6 == 0xfff) {
      sVar6 = 0;
    }
    uac_wservice_for_ap_bind_vlan(sVar6,uVar1,_wportal_collect_ssid_info_cb,auStack_38);
    local_3c = FUN_00407fe0(auStack_38);
    local_150 = 0x1a;
    if (local_3c != '\0') {
      local_150 = 0x19;
    }
    local_148 = &local_c0;
    memset(&local_144,0,0x84);
    local_278[0] = '\0';
    local_278[1] = '\0';
    local_278[2] = '\0';
    local_278[3] = 'd';
    snprintf(acStack_140,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
             g_portal_port);
    local_144 = (uint)*(ushort *)(param_2 + 0x1f8);
    local_154 = 2;
    local_14c = &local_144;
    iVar2 = _wportal_update_wportal_cb(uVar1,&local_154);
    FUN_0051ad88(&local_160);
    if (iVar2 == 0) {
      uVar3 = 0;
      if (*param_3 == '\0') {
        cVar4 = param_3[0x80];
      }
      else {
        for (; uVar3 < 0x80; uVar3 = uVar3 + 1) {
          local_278[uVar3 + 0x70] = param_3[uVar3 + 0x80];
        }
        local_188 = *(undefined4 *)(param_3 + 0x154);
        local_184 = *(undefined4 *)(param_3 + 0x158);
        local_180 = *(undefined4 *)(param_3 + 0x15c);
        local_178 = 1;
        local_174 = 1;
        local_170 = 0xffffffff;
        uVar5 = *(undefined4 *)param_3;
        uVar7 = *(undefined4 *)(param_3 + 4);
        uVar8 = *(undefined4 *)(param_3 + 8);
        uVar9 = *(undefined4 *)(param_3 + 0xc);
        for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
          local_278[uVar3] = param_3[uVar3 + 0x10];
        }
        local_17c = uVar1;
        FUN_00413e94(uVar5,uVar7,uVar8,uVar9);
        cVar4 = param_3[0x80];
      }
      uVar3 = 0;
      if (cVar4 != '\0') {
        for (; uVar3 < 0x80; uVar3 = uVar3 + 1) {
          local_278[uVar3 + 0x70] = param_3[uVar3 + 0x80];
        }
        local_188 = *(undefined4 *)(param_3 + 0x154);
        local_184 = *(undefined4 *)(param_3 + 0x158);
        local_180 = *(undefined4 *)(param_3 + 0x15c);
        local_178 = 2;
        local_174 = 1;
        local_170 = 0xffffffff;
        uVar5 = *(undefined4 *)param_3;
        uVar7 = *(undefined4 *)(param_3 + 4);
        uVar8 = *(undefined4 *)(param_3 + 8);
        uVar9 = *(undefined4 *)(param_3 + 0xc);
        for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
          local_278[uVar3] = param_3[uVar3 + 0x10];
        }
        local_17c = uVar1;
        FUN_00413e94(uVar5,uVar7,uVar8,uVar9);
      }
      iVar2 = _wportal_db_support_new_portal_by_id(uVar1);
      if ((iVar2 != 0) && (g_portal_auth_mode == 0)) {
        __s = (void *)FUN_00408450(0x10,0x1d56);
        if (__s == (void *)0x0) {
          return 0xffffffff;
        }
        memset(__s,0,0x10);
        *(byte *)((int)__s + 0xc) = (byte)*param_1 & 0xf;
        *(undefined1 *)((int)__s + 0xd) = *(undefined1 *)(param_1 + 1);
        *(undefined1 *)((int)__s + 0xe) = *(undefined1 *)(param_2 + 0x127);
        FUN_004086b0(&local_160,__s);
        wportal_update_ssid_portal_switch_to_ap(uVar1,&local_160,0);
      }
    }
    while (iVar2 = FUN_004081b0(&local_160), iVar2 != 0) {
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}

