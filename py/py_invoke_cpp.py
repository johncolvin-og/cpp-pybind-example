from pathlib import Path
import sys
import argparse


def _get_parser():
    parser = argparse.ArgumentParser('Connect to cme market data websocket')
    parser.add_argument(
        '--cme-hooks',
        help='Path to the cme-hooks module',
    )
    parser.set_defaults(
        cme_hooks='build/debug/src/lib_cme_hooks/')
    return parser

if __name__ == '__main__':
    parser = _get_parser()
    args = parser.parse_args()
    current_dir = Path(__file__).parent.parent.absolute()
    # Import bts_cme_hooks module
    module_dir = current_dir.joinpath(args.cme_hooks)
    if module_dir not in sys.path:
        print(f'appending {module_dir}')
        sys.path.append(str(module_dir))
        import cme_hooks
    try:
        print(cme_hooks.add(4, 5))
        cme_hooks.CmeHooks().on_depth("sweet")
    except Exception as e:
        print(f'{__file__} failed: {e}')
        exit(1)

