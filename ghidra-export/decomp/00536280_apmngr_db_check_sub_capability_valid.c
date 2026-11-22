// func apmngr_db_check_sub_capability_valid @ 00536280 size=56

bool apmngr_db_check_sub_capability_valid(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = param_2 < 6;
  if (param_1 != 0x2c) {
    if (param_1 == 0x5f) {
      return param_2 == 1;
    }
    bVar1 = false;
    if (param_1 == 2) {
      bVar1 = param_2 < 2;
    }
  }
  return bVar1;
}

