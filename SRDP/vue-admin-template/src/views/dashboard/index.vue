<template>
  <div class="dashboard-container">
    <h1>首页</h1>
    <div class="firstContainer">
      <span>课程选择</span>
      <span>已选课程查询</span>
      <span>选课推荐</span>
    </div>
    <h2>课程表</h2>
    <div class="kecheng">已选课程表显示限选、已选课、已选人数</div>
    <div class="imgcon" style="textAlign:center;marginTop:20px;">
      <img src="../../img/biao.png" alt="" style="width:1200px;height:600px">
    </div>
  </div>
</template>

<script>
import { mapGetters } from 'vuex'

export default {
  name: 'Dashboard',
  computed: {
    ...mapGetters([
      'name'
    ])
  }
}
</script>

<style lang="scss" scoped>
.dashboard {
  &-container {
    margin: 30px;
  }
  &-text {
    font-size: 30px;
    line-height: 46px;
  }

}
  .firstContainer{
    display: flex;
    width: 40%;
    justify-content: space-around;
    font-size: 20px;
  }
  .kecheng{
    font-size: 20px;
  }
</style>
