
<template>
<div class = homePage>
  <div class = "introduction">
    <span class = "introductionText"> Introduction </span>
    <p class = "introPara"> {{introduction}} </p>
  </div>
  <div class = "introduction">
    <span class = "introductionText"> Academic Information </span>
    <p class = "introPara"> {{academic}} </p>
  </div>
  <div class = "introduction">
    <span class = "introductionText"> Professional Information </span>
    <p class = "introPara"> {{professional}} </p>
  </div>
  <div class = "introduction">
    <span class = "introductionText"> Hobbies </span>
    <p class = "introPara"> {{hobbies}} </p>
  </div>
  <div class = "introduction">
    <span class = "introductionText"> Family </span>
    <p class = "introPara"> {{family}} </p>
  </div>
</div>
</template>

<script>

export default {
  name: 'HomePage',
  data () {
    return {
      introduction: 'Self Confidence is the best outfit and that is what I believe in. My name is Joy Shalom Soosai Michael, born to Mr.Soosai Michael and Mrs.Esther Michael. I am originally from Chennai,India where I completed my schooling and under graduate studies. I worked for Cognizant Technology Solutions, India for close to 3 years as a Product Tester. With a great calling to pursue higher education, I moved to USA in 2017 and started my Masters in Computer Engineering at Syracuse University',
      professional: 'My 2 years and 7 months of work experience at Cognizant Technology, India was of great help in indentifying the right approach in terms of career and learnt the kind of work I enjoyed. I was working as a product tester for a leading financial instituation based in USA for initial 1 year and later moved to work as a database administrator for the same client. I figured out my passion for teaching when I was put to train new employees on various banking products in deposits and collection/Recovery. Entire experience molded and prepared me for future. Im currently working as an intern at CCC Information Services, Chicago as a product developer. My work here enhanced me on a whole and helped me understand that coding is only 50% of work done in an organization and there are other inter related things needed to make it a whole product available to users',
      academic: 'I completed my schooling at C.S.I Ewarts Matriculation School in 2010. I progressed further to start my bachelors in computer engineering at Anna University and completed in 2014 with a cgpa of 3.85 which paved way for further opportunities. I started masters in computer engineering at Syracuse University in 2017 and will graduate in december 2018',
      hobbies: 'My most favorite hobbies are spending time on quora either reading or writing answers. I love designing my clothes, house and have great interest in gardening',
      family: 'We are a family of 5. I have two siblings Mr.John Wesley and Ms.Joy Mercy. We are a close knit family and believe in family comes first at any circumstance'

    }
  },
  methods: {

  }
}
</script>

<style>
  .homePage{
    overflow: auto;
    margin-left: 220px;
    margin-top: 7em;
    width:80%;
    height:60%;
    position: fixed;
  }
  .introduction{
    border-style: groove;
    margin-left: 40px;
  }

  .introductionText{
    font-size: 20px;
    font-family: 'Times New Roman', Times, serif;
    color:  rgb(92, 4, 4);

  }

  .introPara{
    color:#E27D60;
    justify-content: left;
  }
  ::-webkit-scrollbar {
    width: 10px;
    height: 15px;
  }
  ::-webkit-scrollbar-track-piece  {
    background-color:#E27D60;
  }
  ::-webkit-scrollbar-thumb:vertical {
    height: 30px;
    background-color: rgb(92, 4, 4);
  }
</style>
