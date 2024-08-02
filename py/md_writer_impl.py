import myplugin

class MdWriterImpl(myplugin.MdWriter):
    def write_md(self, value):
        print(f'writing market data: {value}')
