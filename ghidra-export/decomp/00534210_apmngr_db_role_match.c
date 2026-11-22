// func apmngr_db_role_match @ 00534210 size=24

bool apmngr_db_role_match(int param_1,uint param_2)

{
  return (1 << (param_1 + 0x10U & 0x1f) & param_2) != 0;
}

