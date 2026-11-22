// func _ucl_auth_offline_station_cmp_func @ 004a77d0 size=56

bool _ucl_auth_offline_station_cmp_func
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_t9;
  
  iVar1 = (**(code **)(in_t9 + 0x2b1eb8))(param_1 + 0xc,param_2,6,param_4,in_t9 + 0x2b9930);
  return iVar1 == 0;
}

