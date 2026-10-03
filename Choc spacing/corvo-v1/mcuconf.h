// Copyright 2026 Gabriel Taborda
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

/* P20/GP28 e P21/GP29 usam o periferico I2C0 do RP2040. */
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE

/* O I2C1 padrao usaria GP2/GP3, que pertencem a matriz de teclas. */
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 FALSE
