// func sso_notify_read_uci_config @ 0043aa38 size=520

undefined4 sso_notify_read_uci_config(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_1d8;
  char local_1d4 [8];
  char acStack_1cc [32];
  undefined4 local_1ac;
  char *local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined2 local_194;
  undefined2 local_192;
  char *local_190;
  undefined4 local_18c;
  undefined4 local_188;
  char *local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined2 local_170;
  undefined2 local_16e;
  char *local_16c;
  undefined4 local_168;
  undefined4 local_164;
  char *local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined2 local_14c;
  undefined2 local_14a;
  undefined1 *local_148;
  undefined4 local_144;
  undefined4 local_140;
  char *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined2 local_128;
  undefined2 local_126;
  undefined4 *local_124;
  undefined4 local_120;
  undefined1 auStack_11c [260];
  
  local_1d4[0] = '\0';
  local_1d4[1] = '\0';
  local_1d4[2] = '\0';
  local_1d4[3] = '\0';
  local_1d4[4] = 0;
  memset(acStack_1cc,0,0x20);
  memset(auStack_11c,0,0x100);
  local_1d8 = 0;
  local_1ac = 0;
  local_1a4 = 1;
  local_1a8 = "sso_enable";
  local_1a0 = 1;
  local_192 = 5;
  local_19c = 0;
  local_198 = 0;
  local_194 = 1;
  local_184 = "sso_type";
  local_16e = 0x20;
  local_18c = 0;
  local_164 = 2;
  local_188 = 1;
  local_180 = 1;
  local_17c = 0;
  local_160 = "sso_sangfor_server";
  local_178 = 0;
  local_14a = 0x100;
  local_174 = 0;
  local_140 = 3;
  local_170 = 1;
  local_168 = 0;
  local_13c = "sso_sangfor_port";
  local_15c = 1;
  local_158 = 0;
  local_154 = 0;
  local_150 = 0;
  local_14c = 1;
  local_144 = 0;
  local_138 = 0;
  local_12c = 10;
  local_134 = 0;
  local_126 = 4;
  local_124 = &local_1d8;
  local_130 = 0;
  local_128 = 1;
  local_120 = 0;
  local_190 = local_1d4;
  local_16c = acStack_1cc;
  local_148 = auStack_11c;
  iVar1 = FUN_00408120("authentication","portal",&local_1ac,4);
  if (iVar1 == 0) {
    iVar1 = strcmp(acStack_1cc,"sangfor");
    iVar2 = strcmp(local_1d4,"on");
    sso_enable_set(iVar2 == 0,iVar1 == 0);
    uVar3 = 0;
    if (iVar1 == 0) {
      sso_sangfor_config_set(auStack_11c,local_1d8);
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d uci req parse failed.\n","sso_notify_read_uci_config",0x2a);
    }
  }
  return uVar3;
}

