// func rdmngr_db_generate_ap_id @ 0061ae68 size=8

uint rdmngr_db_generate_ap_id(int param_1)

{
  return (uint)(param_1 << 4) >> 8;
}

