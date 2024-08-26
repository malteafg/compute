import kp


def main():
    mgr = kp.Manager()

    print(mgr.list_devices())
    print(mgr.get_device_properties())


if __name__ == '__main__':
    main()
