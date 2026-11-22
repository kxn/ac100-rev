// func cloud_mngt_jcs_alias_changed @ 0049806c size=208

void cloud_mngt_jcs_alias_changed(void)

{
  int iVar1;
  undefined4 local_b0;
  char *local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined2 local_98;
  undefined2 local_96;
  char *local_94;
  undefined4 local_90;
  char local_8c [132];
  
  memset(local_8c,0,0x81);
  local_b0 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_ac = "dev_alias";
  local_a8 = 1;
  local_a4 = 1;
  local_98 = 1;
  local_90 = 0;
  local_96 = 0x81;
  local_94 = local_8c;
  iVar1 = FUN_00408120("system",&DAT_00699be8,&local_b0,1);
  if (iVar1 == 0) {
    if (local_8c[0] != '\0') {
      FUN_00408270(local_8c);
    }
  }
  else if (cloud_mngt_err_switch != '\0') {
    printf("[CLOUD_MNGT_ERROR]%s()/%d uci req parse failed.\n","cloud_mngt_jcs_alias_changed",0x1ecc
          );
  }
  return;
}

