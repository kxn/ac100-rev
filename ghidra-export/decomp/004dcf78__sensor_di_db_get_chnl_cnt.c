// func _sensor_di_db_get_chnl_cnt @ 004dcf78 size=60

undefined4 _sensor_di_db_get_chnl_cnt(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xd;
  if ((((param_1 != '\x01') && (uVar1 = 8, param_1 != '\x02')) && (uVar1 = 0xc, param_1 != '\x03'))
     && (uVar1 = 5, param_1 != '\x04')) {
    uVar1 = 0;
  }
  return uVar1;
}

