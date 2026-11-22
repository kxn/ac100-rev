// func apmngr_db_is_ap_exceed @ 00541420 size=144

bool apmngr_db_is_ap_exceed(int param_1,int param_2)

{
  bool bVar1;
  
  if (param_1 == 2) {
    return apmngr_real_ap_num_max <= (int)(g_apmngr_ap_num + 1);
  }
  if (param_1 == 3) {
    bVar1 = true;
    if (((int)(uint)g_apmngr_sensor_num < apmngr_sensor_num_max) && (bVar1 = false, param_2 != 0)) {
      bVar1 = apmngr_firm_sensor_num_max <= (int)(uint)g_apmngr_firm_sensor_num;
    }
    return bVar1;
  }
  return apmngr_real_ap_num_max <= (int)(uint)g_apmngr_ap_num;
}

