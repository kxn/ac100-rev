// func _uac_rdmngr_para_adjust_by_freq @ 00626ff4 size=192

void _uac_rdmngr_para_adjust_by_freq(int param_1,undefined4 param_2)

{
  undefined2 uVar2;
  int iVar1;
  undefined1 auStack_400 [280];
  undefined1 auStack_2e8 [536];
  undefined1 auStack_d0 [196];
  
  memset(auStack_400,0,0x114);
  memset(auStack_2e8,0,0x2d8);
  if (param_1 != 0) {
    uVar2 = rdmngr_db_generate_ap_id(*(undefined4 *)(param_1 + 4));
    iVar1 = apmngr_db_entry_get_by_id(uVar2,auStack_2e8);
    if ((iVar1 == 0) &&
       (iVar1 = apdb_get_radio_by_id
                          (param_2,auStack_d0,*(undefined1 *)(param_1 + 3),auStack_400,
                           (int)*(char *)(param_1 + 8)), iVar1 == 0)) {
      *(undefined1 *)(param_1 + 0x3a) = 0xff;
      *(undefined2 *)(param_1 + 0x3c) = 0xffff;
      *(undefined1 *)(param_1 + 0x40) = 0xff;
      rdmngr_db_init_comPara
                (param_2,param_1 + 4,(int)*(char *)(param_1 + 8),*(undefined1 *)(param_1 + 0x48));
    }
  }
  return;
}

