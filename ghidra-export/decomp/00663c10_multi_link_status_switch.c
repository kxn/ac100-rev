// func multi_link_status_switch @ 00663c10 size=224

int multi_link_status_switch
              (undefined2 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int local_2f8 [2];
  undefined1 auStack_2f0 [20];
  int local_2dc;
  
  memset(auStack_2f0,0,0x2d8);
  iVar1 = _multi_link_status_switch(param_1,param_2,param_3,param_4,param_5,param_6);
  if (((iVar1 == 0) && (iVar2 = apmngr_db_entry_get_by_id(param_1,auStack_2f0), iVar2 == 0)) &&
     ((local_2dc == 1 || ((local_2dc == 3 || (local_2dc == 2)))))) {
    local_2f8[0] = (uint)CONCAT21(param_1,param_2) << 8;
    apmngr_db_foreach_proc(0xff70ffff,_multi_link_child_status_set,local_2f8);
  }
  return iVar1;
}

