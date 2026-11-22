// func wportal_radius_server_table_add @ 0041fa88 size=264

int wportal_radius_server_table_add
              (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined1 local_15c [28];
  undefined1 auStack_140 [288];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar3 = -1;
  if (((param_2 >> 0x18) - 1 & 0xff) < 2) {
    local_res4 = param_2;
    local_res8 = param_3;
    local_resc = param_4;
    memset(auStack_140,0,0x134);
    iVar3 = wportal_db_rds_srv_get_by_index(param_1,auStack_140);
    if (iVar3 == 0) {
      for (uVar1 = 0; uVar1 < 0x14; uVar1 = uVar1 + 1) {
        local_15c[uVar1] = *(undefined1 *)((int)&local_res4 + uVar1);
      }
      iVar2 = FUN_004085c0(local_20,local_1c,local_18,local_14,local_10);
      iVar3 = 0;
      if (iVar2 == 0) {
        iVar3 = FUN_00407eb0(local_20,local_1c,local_18,local_14,local_10);
        if (iVar3 != 0) {
          wportal_db_rds_srv_hash_del(param_1);
        }
        memcpy(&local_20,&local_res4,0x14);
        iVar3 = wportal_db_rds_srv_hash_add(auStack_140);
      }
    }
  }
  return iVar3;
}

