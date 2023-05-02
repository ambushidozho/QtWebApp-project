#include "../Headers/mainwindow.h"
#include "../Mocks/MockMetricsUseCase.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class mainwindowTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        
    }
    void TearDown() override
    {

    }
};


TEST_F(mainwindowTest, RefreshGUIdataTest){
    MockMetricsUseCase* mockusecase = new MockMetricsUseCase();
    MainWindow mw;
    mw.setUseCase(mockusecase);
    EXPECT_CALL(*mockusecase, RefreshData(_));
    mw.RefreshGUIdata();
    delete mockusecase;
}

// непонятно как тестить мейнвиндоу потому что чтобы создать его нужно создать Qapp