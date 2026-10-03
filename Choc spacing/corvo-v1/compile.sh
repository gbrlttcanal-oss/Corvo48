#!/usr/bin/env bash

set -euo pipefail

keyboard_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
qmk_root="$(cd "$keyboard_dir/../../.." && pwd)"
firmware_name="gbrtzt_corvov1_vial.uf2"

cd "$qmk_root"
qmk compile -kb gbrtzt/corvov1 -km vial

if [[ ! -f "$qmk_root/$firmware_name" ]]; then
    echo "Erro: o QMK terminou sem criar $firmware_name" >&2
    exit 1
fi

mv -f "$qmk_root/$firmware_name" "$keyboard_dir/$firmware_name"

echo
echo "Firmware criado em:"
echo "$keyboard_dir/$firmware_name"
