// func apupd_clear_sys_model @ 00658a04 size=424

void apupd_clear_sys_model(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_8e0 [36];
  undefined4 local_8bc;
  undefined4 local_8b8;
  undefined4 local_8b4;
  undefined4 local_8b0;
  char acStack_898 [128];
  undefined1 auStack_818 [88];
  undefined4 local_7c0;
  
  memset(acStack_898,0,0x80);
  if ((*(char *)(param_1 + 0x139) == '\x01') && (*(int *)(param_1 + 0x7ec) == 1)) {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: AUTO Delete sys old_model upgrade task model_id is %u\r\n",
             "apupd_clear_sys_model",0xd22,*(undefined4 *)(param_1 + 0x58));
    }
    memset(auStack_818,0,0x800);
    local_7c0 = *(undefined4 *)(param_1 + 0x58);
    apupd_clear_model(auStack_818,*(undefined4 *)(param_1 + 0x7ec));
    memset(acStack_898,0,0x80);
    local_8bc = 0;
    local_8b8 = 0;
    local_8b4 = 0;
    local_8b0 = 0;
    memset(auStack_8e0,0,0x21);
    FUN_004084f0(param_1 + 0x119,0x10,&local_8bc);
    if (param_2 == 0) {
      snprintf(acStack_898,0x7f,"rm /tmp/.ap_force_up_%s_*",&local_8bc);
    }
    else {
      FUN_004084f0(param_2 + 0x58,0x10,auStack_8e0);
      snprintf(acStack_898,0x7f,"rm /tmp/.ap_force_up_%s_%s",&local_8bc,auStack_8e0);
    }
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: exec-[%s]\r\n","apupd_clear_sys_model",0xd36,acStack_898);
    }
    apupd_excute_cmd(acStack_898);
  }
  return;
}

