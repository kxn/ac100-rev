// func apmngr_db_is_template_exceed @ 005414b0 size=28

bool apmngr_db_is_template_exceed(void)

{
  return apmngr_template_num_max <= (int)(uint)g_apmngr_template_num;
}

