// func acpdt_ac_descriptor_add @ 00664e60 size=632

undefined4 acpdt_ac_descriptor_add(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  char *local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  char *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  char acStack_120 [128];
  char acStack_a0 [132];
  
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_150 = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_13c = (char *)0x0;
  local_168 = 0;
  local_164 = 0;
  local_160 = 0;
  local_15c = 0;
  local_158 = 0;
  local_154 = (char *)0x0;
  memset(acStack_a0,0,0x80);
  memset(acStack_120,0,0x80);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
    uVar5 = 0x112;
  }
  else {
    FUN_0051ad88(&local_12c);
    uVar1 = wsta_db_get_total_num();
    if (0xffff < uVar1) {
      uVar1 = 0xffff;
    }
    uVar2 = *(uint *)(param_2 + 0xa8);
    if (0xffff < uVar2) {
      uVar2 = 0xffff;
    }
    local_138 = CONCAT22((short)uVar1,(short)uVar2);
    uVar1 = apmngr_db_active_ap_num_get();
    if (0xffff < uVar1) {
      uVar1 = 0xffff;
    }
    uVar2 = 0xffff;
    if (*(uint *)(param_2 + 0xa4) < 0x10000) {
      uVar2 = *(uint *)(param_2 + 0xa4);
    }
    local_134 = CONCAT22((short)uVar1,(short)uVar2);
    local_130 = CONCAT13(*(undefined1 *)(param_2 + 0xac),
                         CONCAT12(*(undefined1 *)(param_2 + 0xad),local_130._2_2_));
    local_130 = CONCAT31(local_130._0_3_,*(undefined1 *)(param_2 + 0xae));
    memset(acStack_a0,0,0x80);
    sprintf(acStack_a0,"%d.%d.%d Build %d Rel.%05d",*(undefined4 *)(param_2 + 0x80),
            *(undefined4 *)(param_2 + 0x84),*(undefined4 *)(param_2 + 0x88),
            *(undefined4 *)(param_2 + 0x8c),*(undefined4 *)(param_2 + 0x90));
    local_144 = 0x12345678;
    local_140._0_2_ = 5;
    sVar3 = strlen(acStack_a0);
    local_140 = CONCAT22(local_140._0_2_,(short)sVar3);
    local_13c = acStack_a0;
    FUN_004086b0(&local_12c,&local_150);
    memset(acStack_120,0,0x80);
    sprintf(acStack_120,"%s v%d.%d",param_2,*(undefined4 *)(param_2 + 0x94),
            *(undefined4 *)(param_2 + 0x98));
    local_15c = 0x12345678;
    local_158._0_2_ = 4;
    sVar3 = strlen(acStack_120);
    local_158 = CONCAT22(local_158._0_2_,(short)sVar3);
    local_154 = acStack_120;
    FUN_004086b0(&local_12c,&local_168);
    iVar4 = cw_service_msg_add(param_1,1,&local_138,0);
    if (iVar4 != -1) {
      return 0;
    }
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACPDT_ERROR] %32s() %05d: add ac descriptor to parsed packet failed.\r\n";
    uVar5 = 0x13a;
  }
  printf(__format,"acpdt_ac_descriptor_add",uVar5);
  return 0xffffffff;
}

